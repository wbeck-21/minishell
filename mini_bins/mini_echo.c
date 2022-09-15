#include "../inc/minishell.h"

static int init_check(char *str, int *i)
{
    int check;
    int j;

    check = 0;
    if (str && !ft_strncmp(str, "-n", 2))
    {
        j = 1;
        while (str[j] && str[j] == 'n')
            j++;
        if (!str[j])
            check = 1;
        else
            check = 0;
    }
    if (check)
        *i = 1;
    return (check);
}

// $? is the return code from the last run process. 
// 0 means no error happened. Other values represent some kind of unusual condition.
static char    *special_case(char *str)
{
    if (!ft_strncmp(str, "$?", 2))
    {
        ft_putchar_fd(g_sig.ex_code, 1);
        str += 2;
    }
    return (str);
}

static int	tilda(char	*str, char	**envp)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "~", 1))
	{
		while (envp[i] && ft_strncmp(envp[i], "HOME=", 5))
			i++;
		if (envp[i])
		{
			if (!*(str + 1))
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(str + 1) && *(str + 1) == '/')
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(str + 1) && *(str + 1) != '/')
			{
				ft_putstr_fd("minishell: no such user or directory: ", 1);
				ft_putstr_fd("\033[1;37m", 1);
				ft_putstr_fd(str + 1, 1);
				return (0);
			}
		}
		else
            ft_putstr_fd("", 1);
	}
	return (1);
}

// echo - команда Unix, предназначенная для отображения строки текста (выводит текст на стандартное устройство вывода).  
// echo -n - не переносит строку

void    mini_echo(char **str, char **envp)
{
    int check;
    int i;

    i = 0;
    check = init_check(str[1], &i);
    while (str[++i])
    {
        if (str[i] && !ft_strncmp(str[i], "-n", 2))
            continue;
        str[i] = special_case(str[i]);
        if (!tilda(str[i], envp))
            str[i]++;
        ft_putchar_fd(str[i], 1);
        if (str[i + 1])
            ft_putchar_fd(' ', 1);
    }
    if (!check)
        ft_putchar_fd('\n', 1);
    g_sig.ex_code = 0;
}
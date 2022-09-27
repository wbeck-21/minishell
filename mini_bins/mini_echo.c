/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:04 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:05 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int init_check(char *cmd, int *i)
{
    int check;
    int j;

    check = 0;
    if (cmd && !ft_strncmp(cmd, "-n", 2))
    {
        j = 1;
        while (cmd[j] && cmd[j] == 'n')
            j++;
        if (!cmd[j])
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
static char    *special_case(char *cmd)
{
    if (!ft_strncmp(cmd, "$?", 2))
    {
        ft_putnbr_fd(g_sig.ex_code, 1);
        cmd += 2;
    }
    return (cmd);
}

static int	tilda(char	*cmd, char	**envp)
{
	int	i;

	i = 0;
	if (!ft_strncmp(cmd, "~", 1))
	{
		while (envp[i] && ft_strncmp(envp[i], "HOME=", 5))
			i++;
		if (envp[i])
		{
			if (!*(cmd + 1))
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(cmd + 1) && *(cmd + 1) == '/')
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(cmd + 1) && *(cmd + 1) != '/')
			{
				ft_putstr_fd("minishell: no such user or directory: ", 1);
				ft_putstr_fd("\033[1;37m", 1);
				ft_putstr_fd(cmd + 1, 1);
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

int    mini_echo(char **cmd, char **envp)
{
    int check;
    int i;

    i = 0;
    check = init_check(cmd[1], &i);
    while (cmd[++i])
    {
        if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
            continue;
        cmd[i] = special_case(cmd[i]);
        if (!tilda(cmd[i], envp))
            cmd[i]++;
        ft_putstr_fd(cmd[i], 1);
        if (cmd[i + 1])
            ft_putchar_fd(' ', 1);
    }
    if (!check)
        ft_putchar_fd('\n', 1);
    g_sig.ex_code = 0;
    return (0);
}
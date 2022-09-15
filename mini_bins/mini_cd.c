#include "../inc/minishell.h"

static void err_cd(char *path)
{
    if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
		g_sig.ex_code = 1;
	}
}

static int  change_pwd(char *pwd, char *old_pwd, t_lst **lst)
{
    t_lst	*tmp_lst;
	char	*tmp;

	tmp_lst = *lst;
    while (tmp_lst && ft_strncmp(tmp_lst->var, "PWD=", 4))
        tmp_lst = tmp_lst->next;
    if (!tmp_lst)
        return (1);
    tmp = ft_strdup("PWD=");
    tmp_lst->var = ft_strjoin(tmp, pwd);
    while (tmp_lst && ft_strncmp(tmp_lst->var, "OLDRWD=", 7))
        tmp_lst = tmp_lst->next;
    if (!tmp_lst)
        return (1);
    tmp = ft_strdup("OLDRWD=");
    tmp_lst->var = ft_strjoin(tmp, old_pwd);
    free(pwd);
    free(old_pwd);
}

static char    *pwd_cur(void)
{
    char    *dir;
    char    *res;
    int     size;

    size = 1;
    while (1)
    {
        dir = malloc(size);
        res = getpwd(dir, size);
        if (!res)
            size++;
        else
            break ;
        free(dir);
    }
    return (dir);
}

void    mini_cd(char *path, t_lst **lst)
{
    char    *pwd;
    char    *old_pwd;
    char    *tmp;

	g_sig.ex_code = 0;
    if (!path || !ft_strncmp(path, "~", 1) || !ft_strncmp(path, "~/", 2))
    {
        tmp = ft_strdup("/Users/");
		tmp = ft_strjoin(tmp, getenv("USER"));
        old_pwd = pwd_cur();
        cndir(tmp);
        if (change_pwd(tmp, old_pwd, lst))
            //
        return (0);
    }   
    old_pwd = pwd_cur();
    err_cd(path);
    pwd = pwd_cur();
    if (change_pwd(tmp, old_pwd, lst))
        //
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:19:54 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:19:54 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
    return (1);
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
        res = getcwd(dir, size);
        if (!res)
            size++;
        else
            break ;
        free(dir);
    }
    return (dir);
}

static void    if_no_change(char *old_pwd, t_lst   **lst)
{
    char	*str[4];
	char	*tmp1;
	char	*tmp2;

	str[0] = ft_strdup("export");
	tmp1 = ft_strdup("PWD=");
	tmp1 = ft_strjoin(tmp1, pwd_cur());
	str[1] = ft_strdup(tmp1);
	free(tmp1);
	tmp2 = ft_strdup("OLDPWD=");
	tmp2 = ft_strjoin(tmp2, old_pwd);
	str[2] = ft_strdup(tmp2);
	str[3] = NULL;
	mini_export(lst, str);
	free(tmp2);
}

int    mini_cd(char *path, t_lst **lst)
{
    char    *pwd;
    char    *old_pwd;
    char    *tmp;
    (void)pwd;
	g_sig.ex_code = 0;
    if (!path || !ft_strncmp(path, "~", 1) || !ft_strncmp(path, "~/", 2))
    {
        tmp = ft_strdup("/Users/");
		tmp = ft_strjoin(tmp, getenv("USER"));
        old_pwd = pwd_cur();
        chdir(tmp);
        if (change_pwd(tmp, old_pwd, lst))
            if_no_change(old_pwd, lst);
        return (0);
    }   
    old_pwd = pwd_cur();
    err_cd(path);
    pwd = pwd_cur();
    if (change_pwd(pwd, old_pwd, lst))
        if_no_change(old_pwd, lst);
    return (0);
}
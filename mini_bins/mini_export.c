/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:17 by wbeck             #+#    #+#             */
/*   Updated: 2022/10/01 16:14:50 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// функция export экспортирует переменные командной оболочки 
// в другие командные оболочки (дочерние).
// Экспортировать из дочки в родительскую командную оболочку нельзя  ;-;

t_lst	*make_copy_env(t_lst	*lst)
{
	t_lst	*copy;

	copy = NULL;
	while (lst)
	{
		if (!copy)
			copy = ft_lstnew_rem(lst->var);
		else
			ft_lstadd_back_rem(&copy, ft_lstnew_rem(lst->var));
		lst = lst->next;
	}
	return (copy);
}

static void	just_print(t_lst	*lst)
{
	while (lst)
	{
		ft_putendl_fd(lst->var, 1);
		lst = lst->next;
	}
}

void    print_sort_env(t_lst *lst) // в утилсы
{
    char	*temp;
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*copy;

	copy = make_copy_env(lst);
	tmp1 = copy;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->var, tmp2->var) > 0)
			{
				temp = tmp1->var;
				tmp1->var = tmp2->var;
				tmp2->var = temp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	just_print(copy);
	ft_lstclear_rem(&copy, del);
}

static int export_check(t_lst *lst, char **cmds)
{
    t_lst   *tmp;
    int     i;

    tmp = lst;
    i = 0;
    if (!cmds[1])
    {
        print_sort_env(tmp); // доделать
        return (0);
    }
    while (cmds[++i])
    {
        if (!ft_strncmp(cmds[i], "=", 1) && ft_strcmp(cmds[i], "="))
        {
            ft_putstr_fd("minishell: ", 2);
            ft_putstr_fd(cmds[i] + 1, 2);
            ft_putendl_fd(" not found", 2);
            if (i == 1 || !ft_strcmp(cmds[1], "="))
                g_sig.ex_code = 1;
            return (0);
        }
    }
    return (1);
}

static int exp_except(char *cmd, int *i)
{
	if (!ft_strcmp(cmd, "=") && *i == 1)
	{
		ft_putendl_fd(ERROR"minishell: bad assigment"TEXT, 2);
		return (0);
	}
	if (!ft_strcmp(cmd, "=") && *i != 1)
	{
		ft_putendl_fd(ERROR"minishell: bad assigment"TEXT, 2);
		(*i)++;
		return (1);
	}
	if (ft_isdigit(*cmd))
	{
		ft_putstr_fd(ERROR"export: not an identifier: ", 2);
		ft_putendl_fd(cmd, 2);
		(*i)++;
		return (1);
	}
	return (2);
}

static int cmp_var_cmd(t_lst **lst, char *cmd)
{
    int i;

    i = 0;
    while (cmd[i] != '=')
        i++;
    while ((*lst)->next)
    {
        if (!ft_strncmp((*lst)->var, cmd, i))
        {
            (*lst)->var = cmd;
            return (1);
        }
        lst = &(*lst)->next;
    }
    return (0);
}

static int make_export(t_lst **lst, char **cmds)
{
    int i;
    int j;
    int res;

    i = 0;
    while (cmds[++i])
    {
        res = exp_except(cmds[i], &i);
        if (!res)
            return (0);
        else if (res == 1)
            continue ;
        j = 0;
        while (cmds[i][j] && cmds[i][j] != '=')
            j++;
        if (!cmds[i][j])
            return (0);
        if (cmp_var_cmd(lst, cmds[i]))
            continue ;
        if (i == 1)
            ft_lstadd_preback(lst, ft_lstnew_rem(cmds[i]));
        else
            ft_lstadd_back_rem(lst, ft_lstnew_rem(cmds[i]));
    }
    return (1);
}

int mini_export(t_lst **lst, char **cmds)
{
    t_lst   *last;
    char    *tmp;
    
    g_sig.ex_code = 0;
    if (!export_check(*lst, cmds))
        return (0);
    last = ft_lstlast_rem(*lst);
    tmp = last->var;
    if (!make_export(lst, cmds))
        return (0);
    ft_lstadd_back_rem(lst, ft_lstnew_rem(tmp));
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:34 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:34 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Следует использовать команду unset для
// удаления переменной из вашего окружения 
// командной оболочки.


static int  unset_check(char *cmd)
{
    if (!cmd)
    {
        ft_putendl_fd("unset: not enough arguments", 2);
		g_sig.ex_code = 1;
        return (0);
    }
    return (1);
}

void    mini_unset(t_lst **lst, char **cmd)
{
    t_lst   *last;
    int     i;

    i = 0;
    if (!unset_check(cmd[1]))
        return ;
    last = ft_lstlast_rem(*lst);
    g_sig.ex_code = 0;
    while (cmd[++i])
    {
        if (!ft_strncmp((*lst)->var, cmd[i], ft_strlen(cmd[i])))
        {
            last = (*lst)->next;
            ft_lstdelone_rem(*lst, del);
            *lst = last;
            break ;
        }
        lst = &(*lst)->next;
    }
}
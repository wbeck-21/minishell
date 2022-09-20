/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:08 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:08 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int mini_env(t_lst *lst)
{
    while (lst)
    {
        ft_putchar_fd(lst->var, 1);
        write(1, "\n", 1);
        lst = lst->next;
    }
	g_sig.ex_code = 0;  
    return (0); 
}
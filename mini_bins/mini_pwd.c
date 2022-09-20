/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:27 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:27 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    mini_pwd(void)
{
    char    *dir;
    char    *res;
    int     size;

    size = 1;
    while (1)
    {
        dir = malloc(size);
        res = getcmd(dir, size);
        if (!res)
            size++;
        else{
            ft_putchar_fd(dir, 1);
            write(1, "\n", 1);
            free(dir);
            break ;
        }
        free(dir);
    }
    g_sig.ex_code = 0;
    return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:13 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:14 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    mini_exit(char *cmd)
{
    int i;

    i = -1;
    if (cmd)
    {
        while (cmd[++i])
        {
            if (!ft_isdigit(cmd[i]) && cmd[i] != '-')
            {
                write(2, "exit\n", 2);
                ft_putendl_fd("\033[1;31m\033[1;37mminishell: exit: a: numeric argument required", 2);
                g_sig.ex_code = 255;
                exit(g_sig.ex_code);
            }
        }
        g_sig.ex_code = ft_atoi(cmd);
    }
    while (g_sig.ex_code < 0)
        g_sig.ex_code = 256 + g_sig.ex_code;
    while (g_sig.ex_code > 255)
		g_sig.ex_code = g_sig.ex_code - 256;
	write(2, "exit\n", 5);
	exit(g_sig.ex_code);
}
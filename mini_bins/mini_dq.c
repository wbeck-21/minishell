/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:01 by wbeck             #+#    #+#             */
/*   Updated: 2022/10/02 14:49:19 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_dq(char *cmd)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putnbr_fd(g_sig.ex_code, 2);
	cmd += 2;
	if (*cmd)
		ft_putstr_fd(cmd, 2);
	ft_putendl_fd("\033[1;37m", 2);
	g_sig.ex_code = 127;
}
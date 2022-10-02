/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:20 by wbeck             #+#    #+#             */
/*   Updated: 2022/10/02 15:08:30 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_history(t_list *history, int i)
{
	while (history)
	{
		i++;
		ft_putstr_fd("  ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("  ", 1);
		ft_putendl_fd(history->content, 1);
		history = history->next;
	}
}

// history позволяет просматривать список 
// ранее выполненных команд
int	mini_history(t_list *history)
{
	int	size;
	int	i;

	if (ft_lstsize(history) <= 16)
		print_history(history, 0);
	else
	{
		i = ft_lstsize(history);
		size = i;
		while (--i != 16)
			history = history->next;
		print_history(history, size - i);
	}
	g_sig.ex_code = 0;
	return (0);
}

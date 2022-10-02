/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:34 by wbeck             #+#    #+#             */
/*   Updated: 2022/10/02 15:13:59 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	unset_check(char *cmd)
{
	if (!cmd)
	{
		ft_putendl_fd("unset: not enough arguments", 2);
		g_sig.ex_code = 1;
		return (0);
	}
	return (1);
}

static bool	check_equal(char	**cmd, int	*i)
{
	if (ft_strchr(cmd[*i], '='))
	{
		ft_putendl_fd(ERROR"unset: option '=' is illigal"TEXT, 2);
		g_sig.ex_code = 1;
		(*i)++;
		return (false);
	}
	return (true);
}

void	mini_unset(t_lst **lst, char **cmd)
{
	t_lst	*last;
	int		i;

	i = 0;
	if (!unset_check(cmd[1]))
		return ;
	last = ft_lstlast_rem(*lst);
	g_sig.ex_code = 0;
	while (cmd[++i])
	{
		if (!check_equal(cmd, &i))
			break ;
		while ((*lst)->next)
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
}

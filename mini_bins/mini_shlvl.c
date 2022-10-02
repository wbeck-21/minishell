/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:30 by wbeck             #+#    #+#             */
/*   Updated: 2022/10/02 15:12:01 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_shlvl(t_mini **mini, char **envp)
{
	char	*tmp;
	int		i;
	t_lst	*lst;

	lst = (*mini)->lst;
	i = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (lst && ft_strncmp(lst->var, "SHLVL=", 6))
		lst = lst->next;
	if (!lst)
	{
		while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
			i++;
		tmp = ft_substr(envp[i], 0, 6);
		envp[i] = ft_strjoin(tmp, "0");
	}
}

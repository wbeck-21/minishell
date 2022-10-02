/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:27:56 by ugina             #+#    #+#             */
/*   Updated: 2022/10/02 14:28:06 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*make_history(char	*str, t_list	*lst)
{
	if (!lst)
		lst = ft_lstnew(str);
	else
		ft_lstadd_back(&lst, ft_lstnew(str));
	return (lst);
}

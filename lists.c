/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:28:24 by ugina             #+#    #+#             */
/*   Updated: 2022/10/02 14:28:29 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*ft_lstlast_rem(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstdelone_rem(t_lst	*lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->var);
	free(lst);
}

void	ft_lstclear_rem(t_lst	**lst, void (*del)(void *))
{
	t_lst	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_rem(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstadd_back_rem(t_lst **lst, t_lst *new)
{
	if (*lst)
		ft_lstlast_rem(*lst)->next = new;
	else
		*lst = new;
}

t_lst	*ft_lstnew_rem(void	*content)
{
	t_lst	*list;

	list = (t_lst *) malloc(sizeof(t_lst));
	if (list)
	{
		list->var = content;
		list->next = 0;
	}
	return (list);
}

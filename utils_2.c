/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:38:42 by ugina             #+#    #+#             */
/*   Updated: 2022/10/02 14:59:08 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_size_pipes(char const	*s, char c)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			size++;
		j = i;
		while (*(s + i) != c && *(s + i))
			i++;
		while (*(s + j) && *(s + j) != c
			&& (*(s + j) == ' ' || *(s + j) == '\t'))
			j++;
		if (j == i)
			size--;
		if (*(s + i))
			i++;
	}
	return (size);
}

void	just_print(t_lst	*lst)
{
	while (lst)
	{
		ft_putendl_fd(lst->var, 1);
		lst = lst->next;
	}
}

void	print_sort_env(t_lst *lst)
{
	char	*temp;
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*copy;

	copy = make_copy_env(lst);
	tmp1 = copy;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->var, tmp2->var) > 0)
			{
				temp = tmp1->var;
				tmp1->var = tmp2->var;
				tmp2->var = temp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	just_print(copy);
	ft_lstclear_rem(&copy, del);
}

t_lst	*make_copy_env(t_lst	*lst)
{
	t_lst	*copy;

	copy = NULL;
	while (lst)
	{
		if (!copy)
			copy = ft_lstnew_rem(lst->var);
		else
			ft_lstadd_back_rem(&copy, ft_lstnew_rem(lst->var));
		lst = lst->next;
	}
	return (copy);
}

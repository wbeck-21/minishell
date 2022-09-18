#include "../inc/minishell.h"

t_lst   *ft_lstnew_rem(void *content)
{
    t_lst   *lst;

    lst = (t_lst *)malloc(sizeof(t_lst));
    if (lst)
    {
        lst->var = content;
        lst->next = 0;
    }
    return (lst);
}

t_lst	*ft_lstlast_rem(t_lst *lst) // t_lstlastlast
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void    ft_lstadd_back_rem(t_lst **lst, t_lst *new)
{
    if (*lst)
        ft_lstlast_rem((*lst)->next = new);
    else
        *lst = new;
}

static t_lst    *ft_lstprelast(t_lst *lst)
{
    if (!lst)
        return (0);
    while (lst->next->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstadd_preback(t_lst **lst, t_lst *new)
{
    if (*lst)
        ft_lstprelast(*lst)->next = new;
    else
        *lst = new;
}
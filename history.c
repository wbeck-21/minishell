#include "minishell.h"

t_list	*make_history(char	*str, t_list	*lst)
{
	// создается узел с нашим водом из консоли
	if (!lst)
		lst = ft_lstnew(str);
	else
		ft_lstadd_back(&lst, ft_lstnew(str));
	return (lst);
}
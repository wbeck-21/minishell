#include "minishell.h"

bool	pre_check(char	*str)
{
	if (!preparser(str))
	{
		ft_putendl_fd(ERROR"Parsing error (open gaps)"TEXT, 2);
		return (false);
	}
	if (!ft_strncmp(str, "\"\"", 2) || !ft_strncmp(str, "\'\'", 2))
		return (false);
	return (true);
}

char	*return_message(char	*str)
{
	free(str);
	ft_putendl_fd(ERROR"Parsing error (undefined symbol)"TEXT, 2);
	return (NULL);
}
void	free_mem(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

t_lst	*ft_lstlastlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_preback(t_lst **lst, t_lst *new)
{
	if (*lst)
		ft_lstlastlast(*lst)->next = new;
	else
		*lst = new;
}
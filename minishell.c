#include "minishell.h"

t_lst	*envp_copy(char *envp[])
{
	t_lst	*list;
	int		i;

	i = 0;
	list = NULL;
	while (envp[i])
	{
		ft_lstadd_back_rem(&list, ft_lstnew_rem(envp[i]));
		i++;
	}
	return (list);
}

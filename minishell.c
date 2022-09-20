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

void minishell(t_mini *mini, char **env, char **str_s)
{
	int	i;
	t_list *tmp;

	i = -1;
	while (1)
	{
		printf("OK");
		sleep(1);
		exec(mini, env);
	}
}
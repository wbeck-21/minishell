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

void minishell(t_mini *mini, char **envp, char **strs)
{
	int	i;
	t_list *temp;

	i = -1;
	while (1)
	{
		printf("OK");
		sleep(1);
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		// strs[++i] = readline("minishell $> ");
		// if (!result_line(&strs[i], &mini->history, mini))
		// 	continue ;
		// mini->list = do_split(strs[i]); //  нужнен массив строк
		// free(strs[i]);
		temp = mini->list;
		while (temp)
		{
			temp->content = insert_inside_gap2(mini->change, temp->content);
			temp = temp->next;
		}
		make_split(&mini->list);
		exec(mini, envp);
		// special_free(mini);
	}
}
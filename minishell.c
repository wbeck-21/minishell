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
	//t_list *tmp;
	(void)env;
	i = -1;
	while (1)
	{
		printf("OK");
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		str_s[++i] = readline(MINISHELL"minishell $> "TEXT); // читает строку из консоли
		if (!result_line(&str_s[i], &mini->history, mini)) // отправляем нашу строку, историю и структуру мини
			continue;
		sleep(1);
	}
}
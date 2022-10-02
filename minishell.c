#include "minishell.h"

void	wait_func(t_mini	*mini, int size)
{
	close(mini->proc.fdout);
	close(mini->proc.fdin);
	while (size--)
		waitpid(-1, &g_sig.ex_code, 0);
}

static void	special_free(t_mini	*mini)
{
	t_list	*tmp;

	tmp = mini->list;
	while (tmp)
	{
		free_mem(tmp->cmd);
		tmp = tmp->next;
	}
	ft_lstclear(&mini->list, free);
}

t_lst	*envp_copy(char *envp[])
{
	t_lst	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (envp[i])
	{
		ft_lstadd_back_rem(&lst, ft_lstnew_rem(envp[i]));
		i++;
	}
	return (lst);
}

void minishell(t_mini *mini, char **env, char **str_s)
{
	int	i;
	t_list *tmp;

	i = -1;
	while (1)
	{
		dup2(mini->cmds.in, STDIN_FILENO);
		dup2(mini->cmds.out, STDOUT_FILENO);
		sigaction(SIGQUIT, &mini->sig, NULL);
		sigaction(SIGINT, &mini->sig, NULL);
		str_s[++i] = readline(MINISHELL"minishell $> "TEXT); // читает строку из консоли
		if (!result_line(&str_s[i], &mini->history, mini)) // отправляем нашу строку, историю и структуру мини
			continue;
		mini->list = do_split(str_s[i]);
		free(str_s[i]);
		tmp = mini->list;
		while (tmp)
		{
			tmp->content = insert_inside_gap2(mini->change, tmp->content);
			tmp = tmp->next;
		}
		make_split(&mini->list);
		exec(mini, env);
		special_free(mini);
	}
}
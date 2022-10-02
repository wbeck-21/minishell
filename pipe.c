/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:38:00 by ugina             #+#    #+#             */
/*   Updated: 2022/10/02 14:38:06 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_pipes(char	*str)
{
	int		i;
	t_pre	pip;

	i = -1;
	pip.pipes = 0;
	while (*(str + ++i))
	{
		if (*(str + i) == '|')
			pip.pipes++;
	}
	if (pip.pipes != get_size_pipes(str, '|') - 1 && pip.pipes != 0)
		return (false);
	return (true);
}

static void	child(t_cmd	*cmds, char	**envp, t_proccess	**proc)
{
	dup2((*proc)->fds[1], STDOUT_FILENO);
	close((*proc)->fds[0]);
	close((*proc)->fds[1]);
	execve(cmds->cmd_path, cmds->list->cmd, envp);
}

static void	parents(t_proccess	**proc)
{
	dup2((*proc)->fds[0], STDIN_FILENO);
	close((*proc)->fds[1]);
	close((*proc)->fds[0]);
}

static void	pipex(t_cmd	*cmds, char	**envp, t_proccess	*proc)
{
	pipe(proc->fds);
	init_cmd_path(&cmds);
	if (!cmds->cmd_path)
		return ;
	g_sig.pid = fork();
	if (!g_sig.pid)
		child(cmds, envp, &proc);
	else
		parents(&proc);
}

void	run_pipes(t_cmd	*cmds, t_proccess	*proc, t_mini	*mini, char	**envp)
{
	int	size;

	size = ft_lstsize(mini->list);
	if (!init_env(mini->lst, cmds))
		return ;
	while (mini->list->next)
	{
		cmds->list = mini->list;
		pipex(cmds, envp, proc);
		free(cmds->cmd_path);
		mini->list = mini->list->next;
	}
	cmds->list = mini->list;
	init_cmd_path(&cmds);
	if (!cmds->cmd_path)
		return ;
	g_sig.pid = fork();
	if (!g_sig.pid)
		execve(cmds->cmd_path, cmds->list->cmd, envp);
	else
		wait_func(mini, size);
	g_sig.pid = 0;
	g_sig.ex_code = WEXITSTATUS(g_sig.ex_code);
	free(cmds->cmd_path);
}

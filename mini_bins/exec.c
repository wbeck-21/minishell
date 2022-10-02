/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:12:56 by anastasia         #+#    #+#             */
/*   Updated: 2022/10/02 14:42:14 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	mini_dup2(t_mini *mini)
{
	if (mini->proc.fdin > 0)
		dup2(mini->cmds.in, STDIN_FILENO);
	if (mini->proc.fdout > 0)
		dup2(mini->cmds.out, STDOUT_FILENO);
}

static void	for_shlvl(t_mini *mini, char **envp)
{
	mini_shlvl(&mini, envp);
	run_pipes(&mini->cmds, &mini->proc, mini, envp);
}

static void	choose(t_mini *mini, char **envp)
{
	if (!ft_strcmp(mini->list->cmd[0], "pwd"))
		mini_pwd();
	else if (!ft_strcmp(mini->list->cmd[0], "cd"))
		mini_cd(mini->list->cmd[1], &mini->lst);
	else if (!ft_strcmp(mini->list->cmd[0], "echo"))
		mini_echo(mini->list->cmd, envp);
	else if (!ft_strcmp(mini->list->cmd[0], "export"))
		mini_export(&mini->lst, mini->list->cmd);
	else if (!ft_strcmp(mini->list->cmd[0], "unset"))
		mini_unset(&mini->lst, mini->list->cmd);
	else if (!ft_strcmp(mini->list->cmd[0], "env"))
		mini_env(mini->lst);
	else if (!ft_strcmp(mini->list->cmd[0], "exit"))
		mini_exit(mini->list->cmd[1]);
	else if (!ft_strcmp(mini->list->cmd[0], "history"))
		mini_history(mini->history);
	else if (!ft_strncmp(mini->list->cmd[0], "$?", 2))
		mini_dq(mini->list->cmd[0]);
	else if (!ft_strcmp(mini->list->cmd[0], "./minishell"))
		for_shlvl(mini, envp);
	else
		run_pipes(&mini->cmds, &mini->proc, mini, envp);
}

void	exec(t_mini *mini, char **envp)
{
	while (mini->list)
	{
		choose(mini, envp);
		mini_dup2(mini);
		mini->list = mini->list->next;
	}
}

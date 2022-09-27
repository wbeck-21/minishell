/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:12:56 by anastasia         #+#    #+#             */
/*   Updated: 2022/09/20 22:25:54 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void mini_dup2(t_mini    *mini)
{
    if (mini->proc.fdin > 0)
        dup2(mini->cmds.in, STDIN_FILENO);
    if (mini->proc.fdout > 0)
        dup2(mini->cmds.out, STDOUT_FILENO);
}

static void    choose(t_mini *mini, char **envp)
{
    if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_pwd();
    else if (!ft_strncmp(mini->list->cmd[0], "cd", 2))
        mini_cd(mini->list->cmd[1], &mini->lst);
    else if (!ft_strncmp(mini->list->cmd[0], "echo", 4))
        mini_echo(mini->list->cmd, envp);
    else if (!ft_strncmp(mini->list->cmd[0], "export", 6))
        mini_export(&mini->lst, mini->list->cmd);
    else if (!ft_strncmp(mini->list->cmd[0], "unset", 5))
        mini_unset(&mini->lst, mini->list->cmd);
    else if (!ft_strncmp(mini->list->cmd[0], "env", 3))
        mini_env(mini->lst);
    else if (!ft_strncmp(mini->list->cmd[0], "exit", 4))
        mini_exit(mini->list->cmd[1]);
    else if (!ft_strncmp(mini->list->cmd[0], "history", 3))
        mini_history(mini->history);
    else if (!ft_strncmp(mini->list->cmd[0], "$?", 2))
        mini_dq(mini->list->cmd[0]);
    else if (!ft_strncmp(mini->list->cmd[0], "./minishell", 11))
    {
        mini_shlvl(mini, envp);
        run_pipes(&mini->cmds, &mini->proc, mini, envp);
    }    
    else
        run_pipes(&mini->cmds, &mini->proc, mini, envp);
}

void    exec(t_mini *mini, char **envp)
{
    while (mini->list)
    {
        choose(mini, envp);
        mini_dup2(mini);
        mini->list = mini->list->next;
    } 
}
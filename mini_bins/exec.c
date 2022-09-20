#include "../inc/minishell.h"

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
        mini->list = mini->list->next;
    }
    
}
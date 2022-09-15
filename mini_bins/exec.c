#include "../inc/minishell.h"

static void    choose(t_mini *mini, char **envp)
{
    if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_pwd();
    else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_cd(mini->list->cmd[0], &mini->lst);
    else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_echo();
    // else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
    //     mini_export();
    // else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
    //     mini_unset();
    else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_env();
    // else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
    //     mini_exit();
    // else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
    //     mini_history();
    else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
        mini_dq(mini->list->cmd[0]);
    // else if (!ft_strncmp(mini->list->cmd[0], "pwd", 3))
    //     for_shlvl();
    else
        write(1, "that's all\n", 12);
}

void    exec(t_mini *mini, char **envp)
{
    while (mini->list)
    {
        choose(mini, envp);
        mini->list = mini->list->next;
    }
    
}
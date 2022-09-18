#include "../minishell.h"


// Заметки
// WEXITSTATUS(status) возвращает восемь младших битов значения, 
// которое вернул завершившийся дочерний процесс. 
// Эти биты могли быть установлены в аргументе функции exit() или 
// в аргументе оператора return функции main(). Этот макрос можно использовать,
// только если WIFEXITED вернул ненулевое значение. 

// fork() — системный вызов в Unix-подобных операционных системах, 
// создающий новый процесс, который является практически полной копией 
// процесса-родителя, выполняющего этот вызов.

static void    init_cmd_path(t_cmd **cmds)
{
    int i;

    i = 0;
    if (!access((*cmds)->list->cmd[0], F_OK))
    {
        (*cmds)->cmd_path = ft_strdup((*cmds)->list->cmd[0]);
        return ;
    }
    while ((*cmds)->paths[i])
    {
        (*cmds)->cmd_path = concat((*cmds)->paths[i], (*cmds)->list->cmd[0]);
        if (!access((*cmds)->cmd_path, F_OK))
            break ;
        free((*cmds)->cmd_path);
        (*cmds)->cmd_path = NULL;
        i++;
    }
    if (!(*cmds)->paths[i])
    {
        ft_putstr_fd("minishell: command not found: ", 2);
        ft_putendl_fd((*cmds)->list->cmd[0], 2);
        g_sig.ex_code = 127;
    }
}

static void    child(t_cmd *cmds, t_proc **proc, char **envp)
{
    dup2((*proc)->fds[1], STDOUT_FILENO);
    close((*proc)->fds[0]);
    close((*proc)->fds[1]);
    execve(cmds->cmd_path, cmds->list->cmd, envp);
}

static void    parent(t_proc **proc)
{
    dup2((*proc)->fds[0], STDIN_FILENO);
    close((*proc)->fds[1]);
    close((*proc)->fds[0]);
}


static void    pipex(t_cmd *cmds, t_proc *proc, char **envp)
{
    pipe(proc->fds);
    init_cmd_path(&cmds);
    if (!cmds->cmd_path)
        return ;
    g_sig.pid = fork();
    if (!g_sig.pid)
        child(cmds, &proc, envp);
    else
        parents(&proc);
}

// init_env() эта функция записывает путь к консольным командам
static int init_env(t_lst *lst, t_cmd *cmds)
{
    int i;

    i = 0;
    while (lst, ft_strncmp("PATH", lst->var, 4))
        lst = lst->next;
    if (lst)
        cmds->paths = ft_split(lst->var + 5, ':');
    else
    {
        cmds->paths = NULL;
        ft_putendl_fd("minishell: PATH not found", 2);
        g_sig.ex_code = 127;
        return (0);
    }
    return (1);
}

void    run_pipes(t_cmd *cmds, t_proc *proc, t_mini *mini, char **envp) // раньше назывался  run
{
    int size;

    size = ft_lstsize(mini->list);
    if (!init_env(mini->lst, cmds))
        return ;
    while (mini->list->next)
    {
        cmds->list = mini->list;
        pipex(cmds, proc, envp);
        free(cmds->cmd_path);
        mini->list = mini->list->next;
    }
    cmds->list = mini->list;
    init_cmd_path(&cmds);
    if (!cmds->cmd_path)
        return ;
    g_sig.pid = fork(); // см выше в Заметки
    if (!g_sig.pid)
        execve(cmds->cmd_path, cmds->list->cmd, envp);
    g_sig.pid = 0;
    g_sig.ex_code = WEXITSTATUS(g_sig.ex_code); // см выше в Заметки
    free(cmds->cmd_path);
}
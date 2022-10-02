#include "minishell.h"

char	*double_join(char	*s1, char	*s2)
{
	char	*temp1;
	char	*res;

	temp1 = ft_strjoin(s1, "/");
	res = ft_strjoin(temp1, s2);
	return (res);
}

void	init_cmd_path(t_cmd	**cmds)
{
	int		i;

	i = 0;
	if (!access((*cmds)->list->cmd[0], F_OK))
	{
		(*cmds)->cmd_path = ft_strdup((*cmds)->list->cmd[0]);
		return ;
	}
	while ((*cmds)->mypaths[i])
	{
		(*cmds)->cmd_path
			= double_join((*cmds)->mypaths[i], (*cmds)->list->cmd[0]);
		if (!access((*cmds)->cmd_path, F_OK))
			break ;
		free((*cmds)->cmd_path);
		(*cmds)->cmd_path = NULL;
		i++;
	}
	if (!(*cmds)->mypaths[i])
	{
		ft_putstr_fd(ERROR"minishell: command not found: "TEXT, 2);
		ft_putendl_fd((*cmds)->list->cmd[0], 2);
		g_sig.ex_code = 127;
	}
}

bool	init_env(t_lst	*lst, t_cmd	*cmds)
{
	while (lst && ft_strncmp("PATH", lst->var, ft_strlen("PATH")))
		lst = lst->next;
	if (lst)
		cmds->mypaths = ft_split(lst->var + 5, ':');
	else
	{
		cmds->mypaths = NULL;
		ft_putendl_fd(ERROR"minishell: PATH not found"TEXT, 2);
		g_sig.ex_code = 127;
		return (false);
	}
	return (true);
}
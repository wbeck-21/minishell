#include "minishell.h"
#include "libft/libft.h"

void	handle_free(char	*str, t_list	*history, t_mini	*mini)
{
	ft_putstr_fd("exit\n", 2);
	free(str);
	if (history)
		ft_lstclear(&history, free);
	if (mini->lst)
		ft_lstclear(&mini->lst, free);
	ft_lstclear_rem(&mini->list, del);
	exit(EXIT_FAILURE);
}

void	actions(int signal_num, siginfo_t *info, void *old_info)
{
	(void)info;
	(void)old_info;
	
	if (signal_num == SIGINT)
	{
		g_sig.ex_code = 130;
		ft_putstr_fd("\b\b\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!g_sig.pid)
			rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		ft_putstr_fd("\b\b", 1);
		rl_on_new_line();
		if (!g_sig.pid)
			rl_redisplay();
		else
		{
			ft_putendl_fd("Quit: 3", 1);
			g_sig.ex_code = 131;
		}
	}
}

t_mini	*zero_init(char	**envp)
{
	t_mini	*mini;

	mini = (t_mini *) malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->change.red_in = 1;
	mini->change.red_out = 2;
	mini->change.pipe = 3;
	mini->change.point_coma = 4;
	mini->change.tilda = 5;
	mini->change.gap = 6;
	mini->list = envp_copy(envp);
	mini->cmds.in = dup(STDIN_FILENO);
	mini->cmds.out = dup(STDOUT_FILENO);
	mini->sig.sa_sigaction = actions;
	mini->sig.sa_flags = SA_SIGINFO;
	mini->history = NULL;
	mini->lst = NULL;
	return (mini);
}

static char	**init_shlvl(char	**envp)
{
	int		i;
	char	*tmp;
	char	*sl;
	int		shlvl;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
		i++;
	if (envp[i])
	{
		shlvl = ft_atoi(envp[i] + 6);
		tmp = ft_substr(envp[i], 0, 6);
		sl = ft_itoa(++shlvl);
		envp[i] = ft_strjoin(tmp, sl);
		free(sl);
	}
	return (envp);
}

int	main(int argc, char **argv, char	**envp)
{
	(void)argc;
	(void)argv;
	
	t_mini		*mini;
	char		*strs[10000];

	g_sig.ex_code = 0;
	envp = init_shlvl(envp);
	mini = zero_init(envp);
	if (!mini)
		return (1);
	minishell(mini, envp, strs);
	//free(mini);
	return (0);
}
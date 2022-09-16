#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL "\033[1;33m"
# define TEXT "\033[1;37m"
# define ERROR "\033[1;31m"

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_sig
{
	pid_t	pid;
	int		ex_code;
}				t_sig;

t_sig	g_sig;

typedef struct s_list
{
	char			*content;
	char			**cmd;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	t_list	*lst;
	char	**mypaths;
	char	*cmd_path;
	int		in;
	int		out;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	int		fdin;
	int		fdout;
}				t_proccess;

typedef struct s_lst
{
	char			*var;
	struct s_lst	*next;
}				t_lst;

typedef struct s_pre
{
	int	gap;
	int	gap2;
	int	pipes;
}				t_pre;

typedef struct s_inside_gap2
{
	char	red_in;
	char	red_out;
	char	pipe;
	char	point_coma;
	char	tilda;
	char	gap;
} t_inside_gap_2;



// тут про эти символы, и более правильные названия, я их оттуда и взяла 
// https://www.howtogeek.com/439199/15-special-characters-you-need-to-know-for-bash/ 

typedef struct s_mini
{
	t_list				*list;
	t_lst				*lst;
	t_list				*history;
	t_cmd				cmds;
	t_proccess			proc;
	t_inside_gap_2		change;
	struct sigaction	sig;
	int					shlvl;
}	t_mini;



typedef struct s_sig
{
	pid_t	pid;
	int		ex_code;
}               t_sig;

typedef struct s_lst
{
	char			*var;
	struct s_lst	*next;
}				t_lst;

typedef struct s_list
{
	char			*content;
	char			**cmd;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	t_list	*lst;
	char	**mypaths;
	char	*cmd_path;
	int		in;
	int		out;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	int		fdin;
	int		fdout;
}				t_proccess;

typedef struct s_inside_gap2
{
	char	in_redirect; // (<)
	char	out_redirect; // (>)
	char	pipe; // (|)
	char	cmd_separator; // бывшая point_coma (;)
	char	tilda; // (~)
	char	gap; // (\')  про эту херь не очень понятно
}				t_inside_gap_2;

t_list	*do_split(char	*str);
void	make_split(t_list	**list);
char	*insert_inside_gap2(t_inside_gap_2	change, char *content);

// bash cmbs
void    mini_cd(char *path, t_lst **lst);
void    mini_dq(char *cmd);
void    mini_echo(char **cmd, char **envp);
void	mini_pwd(void);
void    mini_shlvl(t_mini *mini, char **envp);
void    mini_unset(t_lst **lst, char **cmd);

void	minishell(t_mini *mini, char **env, char **str_s);
t_lst	*envp_copy(char *envp[]);
#endif
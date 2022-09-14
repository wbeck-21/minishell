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
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

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



typedef struct s_mini
{
	t_list				*lst;
	t_lst				*list;
	t_list				*history;
	t_cmd				cmds;
	t_proccess			proc;
	t_inside_gap_2		change;
	struct sigaction	sig;
	int					shlvl;
}				t_mini;



#endif
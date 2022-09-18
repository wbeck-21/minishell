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


void	minishell(t_mini *mini, char **env, char **str_s);
t_lst	*envp_copy(char *envp[]);
bool	result_line(char	**str, t_list	**history, t_mini	*mini);
void	handle_free(char	*str, t_list	*history, t_mini	*mini);
void	del(void *var);
t_list	*make_history(char	*str, t_list	*lst);
bool	pre_check(char	*str);
bool	preparser(char	*str);
char	*do_gap2(char	*str, int i, t_lst	*list, t_inside_gap_2 change);
char	*do_gap(char	*str, int i);
char	*multi_join(char	*str, int i, int j);
char	*multi_join2(char	*s1, char	*s2, int i, int j);
bool	was_heredoc(char	*str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*do_dollar(char	*str, int i, t_lst	*list);
char	*return_message(char	*str);
char	*after_check(char	*str, t_mini	*mini);
void	ft_lstclear_rem(t_lst	**lst, void (*del)(void *));
void	ft_lstadd_back_rem(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast_rem(t_lst *lst);
t_lst	*ft_lstnew_rem(void	*content);
bool	dollar_valid(char	*str, int *i, int j);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strjoin(char const *s1, char const *s2);
char	*dollar_join(char	*tmp, char	*str, int i, int j);
#endif
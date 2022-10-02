#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL "\033[1;33m"
# define TEXT "\033[1;37m"
# define ERROR "\033[1;31m"
# define EXIT "minishell: exit: a: numeric argument required"

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
//# include "libft/libft.h"

typedef struct s_sig
{
	pid_t	pid;
	int		ex_code;
}				t_sig;

extern struct s_sig	g_sig;

typedef struct s_list
{
	char			*content;
	char			**cmd;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	t_list	*list;
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
	char	in_redirect; // (<)
	char	out_redirect; // (>)
	char	pipe; // (|)
	char	cmd_separator; // бывшая point_coma (;)
	char	tilda; // (~)
	char	gap; // (\')  про эту херь не очень понятно
}				t_inside_gap_2;

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
}				t_mini;

char    *pwd_cur(void);
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
int	ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_lstclear(t_list **lst, void (*del)(void*));
char	*ft_itoa(int n);;
void	ft_putstr_fd(char *s, int fd);
char	*dollar_join(char	*tmp, char	*str, int i, int j);
bool	check_pipes(char	*str);
void	ft_putendl_fd(char *s, int fd);
char	*redirect(char	*str, t_mini	**mini);
bool	ft_iskey(char c);
char	*input(char	*str, int *i, t_mini	**mini);
char	*get_filename(char	*str, int i, int *j);
char	*free_fd(char	*str, char *filename, int j, int i);
char	*read_heredoc(char	*lim, char	*str, int i, int j);
bool	check_filename(char	*filename, char	*str);
int	get_size_pipes(char const	*s, char c);
void	ft_lstdelone_rem(t_lst	*lst, void (*del)(void *));
int	ft_isalnum(int c);
int		ft_atoi(const char *str);
t_list	*do_split(char	*str);
void	free_mem(char	**strs);
char	*insert_inside_gap2(t_inside_gap_2	change, char *content);
void	make_split(t_list **list);
int    mini_cd(char *path, t_lst **lst);
void    mini_dq(char *cmd);
void    mini_dq(char *cmd);
int    mini_echo(char **cmd, char **envp);
int 	mini_env(t_lst *lst);
void    mini_exit(char *cmd);
int mini_export(t_lst **lst, char **cmds);
int mini_history(t_list *history);
int    mini_pwd(void);
void    mini_shlvl(t_mini **mini, char **envp);
void    mini_unset(t_lst **lst, char **cmd);
void    ft_lstadd_preback(t_lst **lst, t_lst *new);
void    exec(t_mini *mini, char **envp);
char	**ft_split(char const *s, char c);
void	run_pipes(t_cmd	*cmds, t_proccess	*proc, t_mini	*mini, char	**envp);
void	init_cmd_path(t_cmd	**cmds);
int	ft_lstsize(t_list *lst);
bool	init_env(t_lst	*list, t_cmd	*cmds);
char	*double_join(char	*s1, char	*s2);
void	wait_func(t_mini	*mini, int size);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
t_lst	*ft_lstlastlast(t_lst *lst);
#endif
#ifndef MINISHELL_H
# define MINISHELL_H

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
// # include "parser.h"
// # include "pipe.h"
# include "../libft/libft.h"

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
}	t_mini;

t_list	*do_split(char	*str);
void	make_split(t_list	**list);
char	*insert_inside_gap2(t_inside_gap_2	change, char *content);

#endif
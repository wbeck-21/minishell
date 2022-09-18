#include "minishell.h"

bool	check_pipes(char	*str)
{
	int		i;
	t_pre	pip;

	i = -1;
	pip.pipes = 0;
	while (*(str + ++i))
	{
		if (*(str + i) == '|')
			pip.pipes++;
	}
	if (pip.pipes != get_size_pipes(str, '|') - 1 && pip.pipes != 0)
		return (false);
	return (true);
}
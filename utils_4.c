#include "minishell.h"

bool	pre_check(char	*str)
{
	if (!preparser(str))
	{
		ft_putendl_fd(ERROR"Parsing error (open gaps)"TEXT, 2);
		return (false);
	}
	if (!ft_strncmp(str, "\"\"", 2) || !ft_strncmp(str, "\'\'", 2))
		return (false);
	return (true);
}

char	*return_message(char	*str)
{
	free(str);
	ft_putendl_fd(ERROR"Parsing error (undefined symbol)"TEXT, 2);
	return (NULL);
}
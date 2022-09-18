#include "minishell.h"

char	*after_check(char	*str, t_mini	*mini)
{
	if (!check_pipes(str))
	{
		free(str);
		ft_putendl_fd(ERROR"Parsing error (pipes)"TEXT, 2);
		return (NULL);
	}
	if (!str)
		return (NULL);
	str = redirect(str, &mini);
	return (str);
}

bool	dollar_valid(char	*str, int *i, int j)
{
	while (*(str + *i) && ft_iskey(*(str + *i)))
		(*i)++;
	if (*i == j + 1 || (*str + *i) == '?')
		return (false);
	return (true);
}

char	*dollar_join(char	*tmp, char	*str, int i, int j)
{
	char	*res;

	free(tmp);
	res = ft_substr(str, 0, j);
	tmp = ft_strdup(str + i);
	res = ft_strjoin(res, tmp);
	free(tmp);
	free(str);
	return (res);
}
#include "minishell.h"

char	*multi_join(char	*str, int i, int j)
{
	char	*tmp1;
	char	*tmp2;
	char	*res;

	tmp2 = NULL;
	res = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, i - j - 1);
	if (*(str + i))
		tmp2 = ft_strdup(str + i + 1);
	res = ft_strjoin(res, tmp1);
	free(tmp1);
	if (tmp2)
	{
		res = ft_strjoin(res, tmp2);
		free(tmp2);
	}
	return (res);
}

char	*multi_join2(char	*s1, char	*s2, int i, int j)
{
	char	*res;
	char	*tmp;

	res = ft_substr(s1, 0, j);
	tmp = ft_strdup(s1 + i);
	free(s1);
	res = ft_strjoin(res, s2);
	i = ft_strlen(res);
	res = ft_strjoin(res, tmp);
	free(s2);
	free(tmp);
	return (res);
}
#include "minishell.h"

char	*free_fd(char	*str, char *filename, int j, int i)
{
	char	*res;
	char	*tmp;

	res = ft_substr(str, 0, i);
	tmp = ft_strdup(str + ft_strlen(filename) + j);
	res = ft_strjoin(res, tmp);
	free (tmp);
	free (filename);
	free (str);
	return (res);
}

char	*get_filename(char	*str, int i, int *j)
{
	while (*(str + i) && *(str + i) == ' ' )
		i++;
	if (!*(str + i))
		return (NULL);
	*j = i;
	while (*(str + i) && *(str + i) != ' ')
	{
		if (*(str + i) == '>' && *(str + i - 1) == ' ')
			return (NULL);
		i++;
	}
	return (ft_substr(str, *j, i - *j));
}

char	*multi_join(char	*str, int i, int j)
{
	char	*tmp1;
	char	*tmp2;
	char	*res;

	tmp2 = NULL;
	res = ft_substr(str, 0, j);
	printf("MULTI JOIN res %s\n", res);
	tmp1 = ft_substr(str, j + 1, i - j - 1);
	printf("MULTI JOIN tmp1 %s\n", res);
	if (*(str + i))
		tmp2 = ft_strdup(str + i + 1);
	res = ft_strjoin(res, tmp1);
	printf("MULTI JOIN res %s\n", res);
	free(tmp1);
	if (tmp2)
	{
		res = ft_strjoin(res, tmp2);
		free(tmp2);
	}
	printf("MULTI JOIN res %s\n", res);
	return (res);
}

bool	ft_iskey(char c)
{
	return (c == '_' || ft_isalnum(c));
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
#include "libft.h"

int	ft_newline(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_astrjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * ((ft_strlen((char *)s1))
				+ (ft_strlen((char *)s2)) + 1));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free (s1);
	return (str);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
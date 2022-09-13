/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:11:32 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/24 13:14:59 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lentab(char const *s, char c)
{
	int	i;
	int	tab_len;
	int	flag;

	i = 0;
	tab_len = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		if (flag && s[i] != c)
		{
			tab_len++;
			flag = 0;
		}
		i++;
	}
	return (tab_len);
}

void	*ft_free(char **res, int i)
{
	while (i > 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

char	**ft_fulltab(char **res, char const *s, char c)
{
	int		arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[3] = 0;
	while (arr[0] < ft_lentab(s, c))
	{
		arr[2] = 0;
		while (s[arr[1]] == c && s[arr[1]])
			arr[1]++;
		arr[3] = arr[1];
		while (s[arr[1]] != c && s[arr[1]])
		{
			arr[1]++;
			arr[2]++;
		}
		if (arr[2] > 0)
		{
			res[arr[0]++] = ft_substr(s, arr[3], arr[2]);
			if (!res[arr[0] - 1])
				return (ft_free(res, arr[0] - 1));
		}
	}
	res[arr[0]] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * ft_lentab(s, c) + 1);
	if (res)
		res = ft_fulltab(res, s, c);
	return (res);
}

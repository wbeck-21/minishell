/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:19:34 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/24 13:15:45 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) <= len)
		size = ft_strlen(s + start);
	else
		size = len;
	res = malloc(sizeof(char) * size + 1);
	if (res)
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			if (i >= start && j < size)
				res[j++] = s[i];
			i++;
		}
		res[j] = '\0';
	}
	return (res);
}

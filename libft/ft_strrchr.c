/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:15:46 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:32:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		res = (char *)&s[i];
	return (res);
}

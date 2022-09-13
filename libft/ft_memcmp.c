/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:09:23 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:30:38 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*res1;
	unsigned char	*res2;
	size_t			i;

	res1 = (unsigned char *)s1;
	res2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (res1[i] != res2[i])
			return (res1[i] - res2[i]);
		i++;
	}
	return (0);
}

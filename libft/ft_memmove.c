/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:09:43 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:30:48 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		s = (char *)src;
		d = (char *)dst;
		while (len-- > 0)
			*(d++) = *(s++);
	}
	else
	{
		s = (char *)src + len;
		d = (char *)dst + len;
		while (len-- > 0)
			*(--d) = *(--s);
	}
	return (dst);
}

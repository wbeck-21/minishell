/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:59 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:31:32 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	templen;

	if (!dst && !src)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	dst += dstlen;
	dstsize -= dstlen;
	if (srclen >= dstsize)
		templen = dstsize - 1;
	else
		templen = srclen;
	ft_memcpy(dst, src, templen);
	*(dst + templen) = 0;
	return (dstlen + srclen);
}

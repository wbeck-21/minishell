/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:15:08 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:32:10 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			&& len - i >= ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

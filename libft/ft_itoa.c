/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:05:59 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/13 16:29:57 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_check1(int *n, int *len, int *flag, int *min_int)
{
	if (*n == -2147483648)
	{
		*n /= 10;
		*min_int = 1;
	}
	if (*n < 0)
	{
		*n *= -1;
		*flag = 1;
	}
	*len = ft_len(*n);
	if (*flag)
		(*len)++;
	if (*min_int)
		(*len)++;
}

void	ft_check2(char *res, int *len, int *flag, int *min_int)
{
	if (*flag)
		res[0] = '-';
	if (*min_int)
	{
		res[(*len) - 1] = '8';
		(*len)--;
	}
}

char	*ft_res(int n, int len, char *res)
{
	while (len > 0 && n)
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		len;
	int		min_int;
	char	*res;

	flag = 0;
	min_int = 0;
	if (n == 0)
	{
		res = malloc(2);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	ft_check1(&n, &len, &flag, &min_int);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	ft_check2(&(*res), &len, &flag, &min_int);
	return (ft_res(n, len, res));
}

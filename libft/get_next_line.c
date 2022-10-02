/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <ugina@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:14:17 by ugina             #+#    #+#             */
/*   Updated: 2022/10/02 15:14:29 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_liner(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_cut(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*ft_reader(int fd, char *line)
{
	int		last;
	char	*reader;
	int		size;

	size = 21;
	reader = malloc(sizeof(char) * (size + 1));
	if (!reader)
		return (NULL);
	last = 1;
	while (last && !ft_newline(line))
	{
		last = read(fd, reader, size);
		if (last < 0)
		{
			free(reader);
			return (NULL);
		}
		reader[last] = '\0';
		line = ft_astrjoin(line, reader);
	}
	free(reader);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0)
		return (NULL);
	str = ft_reader(fd, str);
	if (!str)
		return (NULL);
	line = ft_liner(str);
	str = ft_cut(str);
	return (line);
}

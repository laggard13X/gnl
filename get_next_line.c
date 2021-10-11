/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edread <edread@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:58:21 by edread            #+#    #+#             */
/*   Updated: 2020/12/08 20:40:41 by edread           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_if(char **buf, char **remain)
{
	if (*buf)
		free(*buf);
	if (*remain)
		free(*remain);
	return (-1);
}

int		if_eof(char **line, char **remain, char **buf)
{
	*line = ft_my_strdup(*remain, '\0');
	free(*remain);
	*remain = NULL;
	free(*buf);
	if (!*line)
		return (-1);
	return (0);
}

int		get_line(char **remain, int fd, char **buf, char **line)
{
	char	*pointer;
	int		b;

	b = 1;
	while (!(pointer = ft_strchr(*remain, '\n')))
	{
		if ((b = read(fd, *buf, BUFFER_SIZE)) > 0)
		{
			(*buf)[b] = '\0';
			*remain = ft_strjoin(*remain, *buf);
			if (!*remain)
				return (free_if(buf, remain));
		}
		else if (b == -1)
			return (free_if(buf, remain));
		else
			return (if_eof(line, remain, buf));
	}
	*line = ft_my_strdup(*remain, '\n');
	if (!*line)
		return (free_if(buf, remain));
	*remain = ft_strcpy(*remain, ++pointer);
	free(*buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*remain;

	if (fd < 0 || fd >= 180 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	buf[0] = '\0';
	return (get_line(&remain, fd, &buf, line));
}

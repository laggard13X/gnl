/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edread <edread@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:15:24 by edread            #+#    #+#             */
/*   Updated: 2020/12/08 20:39:56 by edread           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_my_strdup(const char *src, char c);
char			*ft_strcpy(char *dest, char *src);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

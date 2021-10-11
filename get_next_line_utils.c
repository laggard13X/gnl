/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edread <edread@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:56:49 by edread            #+#    #+#             */
/*   Updated: 2020/12/08 00:16:23 by edread           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		len = ft_strlen((char*)s2);
	else
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[k++] = s1[i++];
	i = 0;
	while (s2[i])
		res[k++] = s2[i++];
	res[k] = '\0';
	free((char *)s1);
	return (res);
}

char		*ft_my_strdup(const char *src, char c)
{
	int		n;
	char	*new;

	n = 0;
	while (src && src[n] != c)
		n++;
	new = (char*)malloc(sizeof(*new) * (n + 1));
	if (new == NULL)
		return (0);
	n = 0;
	while (src && src[n] != c)
	{
		new[n] = src[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}

char		*ft_strcpy(char *dest, char *src)
{
	int n;

	n = 0;
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:37:21 by achater           #+#    #+#             */
/*   Updated: 2024/03/01 20:39:54 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		x;

	x = 1;
	buff = NULL;
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (x != 0 && !(find(str, '\n')))
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[x] = '\0';
		str = ft_strjoin0(str, buff);
	}
	free(buff);
	return (str);
}

static char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*new_rest(char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	i += (s[i] == '\n');
	new = malloc(ft_strlen(s) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		new[j] = s[i + j];
		j++;
	}
	new[j] = '\0';
	free(s);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	rest = new_rest(rest);
	return (line);
}

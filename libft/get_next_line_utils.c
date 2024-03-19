/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:47:17 by achater           #+#    #+#             */
/*   Updated: 2024/03/02 17:17:43 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper(char *s3, char *s2, char *s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin0(char *s1, char *s2)
{
	char	*s3;
	int		i;
	size_t	i1;
	size_t	i2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (!s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = malloc(i1 + i2 + 1);
	if (s3 == NULL)
		return (NULL);
	i = helper(s3, (char *)s2, (char *)s1);
	free(s1);
	s3[i] = '\0';
	return (s3);
}

int	find(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

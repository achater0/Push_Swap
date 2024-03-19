/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:39:36 by achater           #+#    #+#             */
/*   Updated: 2023/11/12 18:04:15 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	f(char *s3, char *s2, char *s1)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	size_t	i1;
	size_t	i2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = malloc(i1 + i2 + 1);
	if (s3 == NULL)
		return (NULL);
	i = f(s3, (char *)s2, (char *)s1);
	s3[i] = '\0';
	return (s3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:56:38 by achater           #+#    #+#             */
/*   Updated: 2023/11/12 18:32:05 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	i = 0;
	if (s == NULL || start >= ft_strlen(s) || len == 0)
	{
		x = (char *)malloc(1);
		if (x == NULL)
			return (NULL);
		x[0] = '\0';
		return (x);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	x = malloc(len + 1);
	if (x == 0)
		return (0);
	while (s[start] && i < len && start <= ft_strlen(s))
	{
		x[i] = s[start];
		start++;
		i++;
	}
	x[i] = '\0';
	return (x);
}

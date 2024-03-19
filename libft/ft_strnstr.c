/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:13:17 by achater           #+#    #+#             */
/*   Updated: 2024/02/22 23:29:37 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayt_stack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)hayt_stack);
	while ((i < len) && hayt_stack[i])
	{
		while (hayt_stack[i + j] == needle[j] && hayt_stack[i + j] != '\0'
			&& (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)hayt_stack + i);
		i++;
		j = 0;
	}
	return (NULL);
}

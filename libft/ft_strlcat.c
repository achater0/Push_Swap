/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:46:06 by achater           #+#    #+#             */
/*   Updated: 2023/11/16 21:23:15 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;
	size_t	t;

	i = 0;
	x = 0;
	t = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (src[i])
		i++;
	while (dst[x] && x < dstsize)
		x++;
	if (x == dstsize)
		return (i + x);
	while (src[t] && (t + x) < dstsize - 1)
	{
		dst[x + t] = src[t];
		t++;
	}
	if ((x + t) < dstsize)
		dst[x + t] = '\0';
	return (i + x);
}

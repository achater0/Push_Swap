/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:23:46 by achater           #+#    #+#             */
/*   Updated: 2023/11/29 17:51:02 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	x = malloc(size * count);
	if (x == 0)
		return (0);
	ft_bzero(x, (count * size));
	return (x);
}

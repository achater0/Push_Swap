/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:49:04 by achater           #+#    #+#             */
/*   Updated: 2023/11/12 17:30:33 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	f(int i, char *x, int len, long nb)
{
	while ((len) > 0)
	{
		x[len - 1 + i] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
}

static int	count(int n)
{
	int		x;
	long	nb;

	nb = n;
	x = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*x;
	int		len;
	int		i;
	long	nb;

	nb = n;
	len = count(nb);
	i = 0;
	if (n < 0)
		i = 1;
	x = malloc(sizeof(char) * len + i + 1);
	if (!x)
		return (NULL);
	if (n < 0)
	{
		x[0] = '-';
		nb *= -1;
	}
	f(i, x, len, nb);
	x[len + i] = '\0';
	return (x);
}

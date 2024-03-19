/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:15:41 by achater           #+#    #+#             */
/*   Updated: 2024/03/13 01:23:18 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(char *str, unsigned long x, int signe)
{
	int		i;
	char	*s;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		signe = 44 - str[i++];
	while (str[i] == '0')
		i++;
	s = malloc(ft_strlen(str) - i + 1);
	if (s == NULL)
		error();
	ft_strlcpy(s, str + i, ft_strlen(str) - i + 1);
	if (ft_strlen(s) > 10)
	{
		free(s);
		error();
	}
	free(s);
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = (x * 10) + str[i] - '0';
		i++;
	}
	return (x * signe);
}

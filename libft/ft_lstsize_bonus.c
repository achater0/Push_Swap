/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:04:23 by achater           #+#    #+#             */
/*   Updated: 2024/02/22 23:44:52 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*x;

	x = lst;
	i = 0;
	while (x)
	{
		i++;
		x = x ->next;
	}
	return (i);
}

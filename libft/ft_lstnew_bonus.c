/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:21 by achater           #+#    #+#             */
/*   Updated: 2024/02/22 23:48:45 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (x == 0)
		return (0);
	x ->content = content;
	x ->next = NULL;
	return (x);
}

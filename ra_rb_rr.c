/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:02:36 by achater           #+#    #+#             */
/*   Updated: 2024/03/01 01:31:28 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*last;

	if (*a && (*a)->next)
	{
		ft_lstlast(*a)->next = *a;
		last = (*a)->next;
		(*a)->next = NULL;
		*a = last;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*last;

	if (*b && (*b)->next)
	{
		ft_lstlast(*b)->next = *b;
		last = (*b)->next;
		(*b)->next = NULL;
		*b = last;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

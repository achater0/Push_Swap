/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:56:29 by achater           #+#    #+#             */
/*   Updated: 2024/03/02 19:52:32 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa1(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pb1(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	ra1(t_stack **a)
{
	t_stack	*last;

	if (*a && (*a)->next)
	{
		ft_lstlast(*a)->next = *a;
		last = (*a)->next;
		(*a)->next = NULL;
		*a = last;
	}
}

void	rb1(t_stack **b)
{
	t_stack	*last;

	if (*b && (*b)->next)
	{
		ft_lstlast(*b)->next = *b;
		last = (*b)->next;
		(*b)->next = NULL;
		*b = last;
	}
}

void	rr1(t_stack **a, t_stack **b)
{
	ra1(a);
	rb1(b);
}

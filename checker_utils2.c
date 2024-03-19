/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:58:52 by achater           #+#    #+#             */
/*   Updated: 2024/03/02 19:52:37 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra1(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;
	int		size;

	size = ft_lstsize(*a);
	if (size < 2)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb1(t_stack **b)
{
	t_stack	*last;
	t_stack	*tmp;
	int		size;

	size = ft_lstsize(*b);
	if (size < 2)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr1(t_stack **a, t_stack **b)
{
	rra1(a);
	rrb1(b);
}

void	sa1(t_stack *a)
{
	int	tmp;
	int	size;

	size = ft_lstsize(a);
	if (size < 2)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

void	sb1(t_stack *b)
{
	int	tmp;
	int	size;

	size = ft_lstsize(b);
	if (size < 2)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
}

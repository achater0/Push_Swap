/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ronin_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:46:24 by achater           #+#    #+#             */
/*   Updated: 2024/03/10 22:21:37 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*min;

	i = 0;
	tmp = a;
	min = a;
	while (min)
	{
		while (tmp)
		{
			if (min->content > tmp->content)
				i++;
			tmp = tmp->next;
		}
		tmp = a;
		min->index = i;
		i = 0;
		min = min->next;
	}
}

int	find_max_pos(t_stack *b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*max;

	i = 0;
	tmp = b;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
	tmp = b;
	max = b;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position);
}

int	find_min_pos(t_stack *b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*min;

	i = 0;
	tmp = b;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
	tmp = b;
	min = b;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->position);
}

void	push_to_b(t_stack **a, t_stack **b, int i, int x)
{
	t_stack	*tmp;

	if (ft_lstsize(*a) <= 100)
		x = 16;
	else
		x = 34;
	while (*a)
	{
		tmp = *a;
		if (tmp->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (tmp->index < i + x)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	push_to_a(t_stack **a, t_stack **b, int j, int i)
{
	j = ft_lstsize(*b);
	while (j)
	{
		i = find_max_pos(*b);
		if ((j / 2) >= i)
		{
			while (i)
			{
				rb(b);
				i--;
			}
			pa(a, b);
		}
		else
		{
			while (i != (j - 1))
			{
				rrb(b);
				i ++;
			}
			rrb(b);
			pa(a, b);
		}
		j--;
	}
}

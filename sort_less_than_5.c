/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:57:06 by achater           #+#    #+#             */
/*   Updated: 2024/03/01 01:38:58 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_than_5(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_3(a, 0, 0);
	else if (size <= 5)
		sort_4_5(a, b);
}

void	sort_3(t_stack **a, int max, int min)
{
	max = find_max_pos(*a);
	min = find_min_pos(*a);
	if (max == 0 && min == 1)
		ra(a);
	else if (max == 0 && min == 2)
	{
		sa(*a);
		rra(a);
	}
	else if (max == 1 && min == 0)
	{
		rra(a);
		sa(*a);
	}
	else if (max == 1 && min == 2)
		rra(a);
	else if (max == 2 && min == 1)
		sa(*a);
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	int	i;
	int	x;

	i = 0;
	while (i < 2)
	{
		x = find_min_pos(*a);
		if ((*a)->position == x)
		{
			pb(a, b);
			i++;
		}
		else
		{
			if (x > ft_lstsize(*a) / 2)
				rra(a);
			else
				ra(a);
		}
	}
	sort_3(a, 0, 0);
	pa(a, b);
	pa(a, b);
}

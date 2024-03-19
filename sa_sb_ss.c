/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:49:26 by achater           #+#    #+#             */
/*   Updated: 2024/03/01 01:37:25 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;
	int	size;

	size = ft_lstsize(a);
	if (size < 2)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;
	int	size;

	size = ft_lstsize(b);
	if (size < 2)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:18 by achater           #+#    #+#             */
/*   Updated: 2024/03/01 01:29:40 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		is_a_digit(char *str);
void	push_back(t_stack **a, int x);
void	check_arg(char **argv, t_stack **a);
void	check_dup(t_stack *a);
void	free_split(char **str);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	error_and_free(char **str);
void	set_index(t_stack *a);
int		find_max_pos(t_stack *a);
void	push_to_b(t_stack **a, t_stack **b, int i, int x);
void	push_to_a(t_stack **a, t_stack **b, int j, int i);
void	sort_3(t_stack **a, int max, int min);
int		find_min_pos(t_stack *a);
void	sort_less_than_5(t_stack **a, t_stack **b);
void	sort_4_5(t_stack **a, t_stack **b);

#endif

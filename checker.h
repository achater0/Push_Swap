/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:30:29 by achater           #+#    #+#             */
/*   Updated: 2024/03/03 17:20:56 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		is_a_digit(char *str);
void	push_back(t_stack **a, int x);
void	check_arg(char **argv, t_stack **a);
void	check_dup(t_stack *a);
void	free_split(char **str);
void	sa1(t_stack *a);
void	sb1(t_stack *b);
void	ss1(t_stack *a, t_stack *b);
void	pa1(t_stack **a, t_stack **b);
void	pb1(t_stack **a, t_stack **b);
void	ra1(t_stack **a);
void	rb1(t_stack **b);
void	rr1(t_stack **a, t_stack **b);
void	rra1(t_stack **a);
void	rrb1(t_stack **b);
void	rrr1(t_stack **a, t_stack **b);
void	error_and_free(char **str);
void	read_and_do(t_stack **a, t_stack **b, char *line);

#endif

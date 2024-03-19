/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:40:38 by achater           #+#    #+#             */
/*   Updated: 2024/03/19 00:16:51 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(char **argv, t_stack **a)
{
	long long	y;
	int			i;
	int			j;
	char		**str;

	i = 1;
	j = 0;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		if (str[0] == NULL)
			error_and_free(str);
		while (str[j])
		{
			y = ft_atoi(str[j], 0, 1);
			if (is_a_digit(str[j]) == 1 || y < -2147483648 || y > 2147483647)
				error_and_free(str);
			push_back(a, y);
			j++;
		}
		j = 0;
		i++;
		free_split(str);
	}
	check_dup(*a);
}

static int	check_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac > 1)
	{
		check_arg(av, &a);
		if (check_stack(a) == 0)
			exit(0);
		if (ft_lstsize(a) < 6)
			sort_less_than_5(&a, &b);
		else
		{
			set_index(a);
			push_to_b(&a, &b, 0, 0);
			push_to_a(&a, &b, 0, 0);
		}
		while (a)
		{
			b = a->next;
			free(a);
			a = b;
		}
	}
	else
		return (0);
}

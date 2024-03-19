/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:31:16 by achater           #+#    #+#             */
/*   Updated: 2024/03/19 00:16:42 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss1(t_stack *a, t_stack *b)
{
	sa1(a);
	sb1(b);
}

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

	if (a == NULL)
		return (1);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	read_and_do(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_strncmp(line, "sa", 2)) && (ft_strlen(line) == 3))
		sa1(*a);
	else if (!(ft_strncmp(line, "sb", 2)) && (ft_strlen(line) == 3))
		sb1(*b);
	else if (!(ft_strncmp(line, "ss", 2)) && (ft_strlen(line) == 3))
		ss1(*a, *b);
	else if (!(ft_strncmp(line, "pa", 2)) && (ft_strlen(line) == 3))
		pa1(a, b);
	else if (!(ft_strncmp(line, "pb", 2)) && (ft_strlen(line) == 3))
		pb1(a, b);
	else if (!(ft_strncmp(line, "ra", 2)) && (ft_strlen(line) == 3))
		ra1(a);
	else if (!(ft_strncmp(line, "rb", 2)) && (ft_strlen(line) == 3))
		rb1(b);
	else if (!(ft_strncmp(line, "rr", 2)) && (ft_strlen(line) == 3))
		rr1(a, b);
	else if (!(ft_strncmp(line, "rra", 3)) && (ft_strlen(line) == 4))
		rra1(a);
	else if (!(ft_strncmp(line, "rrb", 3)) && (ft_strlen(line) == 4))
		rrb1(b);
	else if (!(ft_strncmp(line, "rrr", 3)) && (ft_strlen(line) == 4))
		rrr1(a, b);
	else
		error();
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (ac > 1)
	{
		check_arg(av, &a);
		while (1)
		{
			line = get_next_line(0);
			if (line == NULL)
				break ;
			read_and_do(&a, &b, line);
			free(line);
		}
		if (check_stack(a) == 0 && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		exit(0);
	}
	else
		return (0);
}

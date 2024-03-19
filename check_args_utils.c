/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:54:28 by achater           #+#    #+#             */
/*   Updated: 2024/03/04 17:14:05 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

void	push_back(t_stack **a, int x)
{
	t_stack	*tmp;

	tmp = ft_lstnew(x);
	ft_lstadd_back(a, tmp);
}

void	check_dup(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_and_free(char **str)
{
	free_split(str);
	error();
}

// void print_stack(t_stack *a)
// {
// 	while(a)
// 	{
// 		printf("%d     \n",a->content);
// 		a = a->next;
// 	}
// }
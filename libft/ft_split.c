/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:42 by achater           #+#    #+#             */
/*   Updated: 2024/02/24 23:33:20 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	x;
	int	i;

	if (!s)
		return (0);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 || s[i - 1] == c)
			if (s[i] != c)
				x++;
		i++;
	}
	return (x);
}

static char	**free_substrs(char **substrs)
{
	int	i;

	i = 0;
	while (substrs[i])
	{
		free(substrs[i]);
		i++;
	}
	free(substrs);
	return (0);
}

static void	helper(char const *s, int *len, char c)
{
	if (ft_strchr(s, c))
		*len = ft_strchr(s, c) - s;
	else
		*len = ft_strlen(s);
}

char	**ft_split(char const *s, char c)
{
	char	**substrs;
	int		i;
	int		len;

	if (!s)
		return (0);
	substrs = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!substrs)
		exit(1);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			helper(s, &len, c);
			substrs[i] = ft_substr(s, 0, len);
			if (!substrs[i++])
				return (free_substrs(substrs));
			s += len;
		}
	}
	substrs[i] = 0;
	return (substrs);
}

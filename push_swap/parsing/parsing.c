/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:01:09 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:05:48 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include <stdio.h>
#include "../includes/push_swap.h"

int	check_is_sorted(t_list *a)
{
	while (a->next)
	{
		if (*(int *)a->content >= *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_empty_string_or_max_int(char **av, int ac)
{
	int		i;
	int		j;
	size_t	max;

	i = 0;
	j = 0;
	while (i < ac)
	{
		max = 10;
		if (av[i][0] == '-' || av[i][0] == '+')
		{
			max++;
			j++;
		}
		while (av[i][j] == '0')
		{
			max++;
			j++;
		}
		if (ft_strlen(av[i]) > max)
			return (0);
		i++;
	}
	return (1);
}

static int	check_double(int *nbrs, int len)
{
	int	i;
	int	y;

	i = 0;
	while (i < len)
	{
		y = i + 1;
		while (y < len)
			if (nbrs[i] == nbrs[y++])
				return (1);
		i++;
	}
	return (0);
}

static int	*arrtoi(char **ints, int len)
{
	int		*arr;
	int		i;
	int		y;

	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		y = -1;
		while (ints[i][++y])
			if (!ft_isdigit(ints[i][y])
				&& ints[i][y] != '-' && ints[i][y] != '+')
				return (free(arr), NULL);
		arr[i] = ft_atoi(ints[i]);
		if (ft_atol(ints[i]) < INT_MIN || ft_atol(ints[i]) > INT_MAX)
			return (free(arr), NULL);
	}
	return (arr);
}

int	*ft_parsing(char **argv, int len)
{
	int		*arr;

	if (len < 0)
		return (NULL);
	if (emptystring(argv, len) != 1)
		return (NULL);
	if (check_empty_string_or_max_int(argv, len) != 1)
		return (NULL);
	if (check_only_valid_int(argv, len) != 1)
		return (NULL);
	arr = arrtoi(argv, len);
	if (!arr)
		return (NULL);
	if (check_double(arr, len))
		return ((free(arr), NULL));
	return (arr);
}

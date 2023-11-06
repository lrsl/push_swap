/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:02:50 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/23 11:56:46 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include <stdio.h>
#include "../includes/push_swap.h"

int	check_only_valid_int(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
		{
			j++;
			if (!av[i][j] || ft_isdigit(av[i][j]) == 0)
				return (0);
		}
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	emptystring(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!av[i][0])
			return (0);
		i++;
	}
	return (1);
}

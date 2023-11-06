/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:01:48 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:06:31 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_5(t_list **a, t_list **b, t_data *data)
{
	while (ft_lstsize(*a) > 3)
	{
		if (*(int *)(*a)->content < 3)
			(ft_putstr_fd("pb\n", 1), pb(a, b));
		else
			(ft_putstr_fd("ra\n", 1), ra(a, b));
	}
	if (check_is_sorted(*b))
		(ft_putstr_fd("sb\n", 1), sb(a, b));
	if (!check_is_sorted(*a))
		sorting_3(a, b, data, 5);
	while (*b)
		(ft_putstr_fd("pa\n", 1), pa(a, b));
}

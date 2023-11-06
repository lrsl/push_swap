/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:01:29 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:06:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_3(t_list **a, t_list **b, t_data *data, int max)
{
	t_list	*temp;
	int		i;

	temp = *a;
	i = 0;
	if (check_is_sorted(*a))
		return ;
	while (temp && *(int *)temp->content != max && ++i)
		temp = temp->next;
	if (i == 0)
		(ft_putstr_fd("ra\n", 1), ra(a, b), sorting_3(a, b, data, max));
	if (i == 1)
		(ft_putstr_fd("rra\n", 1), rra(a, b), sorting_3(a, b, data, max));
	if (i == 2)
		(ft_putstr_fd("sa\n", 1), sa(a, b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:46:29 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:06:51 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_sorting_chunk(t_list **a, t_list **b, t_data *data)
{
	while (*a)
	{
		if (*(int *)(*a)->content <= data->start + data->max_value)
		{
			(ft_putstr_fd("pb\n", 1), pb(a, b));
			data->start++;
			if (*(int *)(*b)->content < data->start)
			{
				if ((*a) && *(int *)(*a)->content > data->start
				+ data->max_value)
					(ft_putstr_fd("rr\n", 1), rr(a, b));
				else
					(ft_putstr_fd("rb\n", 1), rb(a, b));
			}
		}
		else
			(ft_putstr_fd("ra\n", 1), ra(a, b));
	}
	data->size = data->total_nb;
}

void	sorting_big_stack(t_list **a, t_list **b, t_data *data)
{
	t_list	*temp;
	int		i;

	stack_sorting_chunk(a, b, data);
	while (*b)
	{
		i = 0;
		temp = *b;
		while (temp && *(int *)temp->content != data->size && ++i)
			temp = temp->next;
		while ((*(int *)(*b)->content != data->size))
		{
			if (i < data->size / 2)
				(ft_putstr_fd("rb\n", 1), rb(a, b));
			else
				(ft_putstr_fd("rrb\n", 1), rrb(a, b));
		}
		(ft_putstr_fd("pa\n", 1), pa(a, b));
		data->size--;
	}
}

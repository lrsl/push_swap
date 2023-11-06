/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:29 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:08:27 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a, t_list **b)
{
	void	*temp;

	(void)b;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
}

void	sb(t_list **a, t_list **b)
{
	void	*temp;

	(void)a;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
}

void	ss(t_list **a, t_list **b)
{
	sa(a, b);
	sb(a, b);
}

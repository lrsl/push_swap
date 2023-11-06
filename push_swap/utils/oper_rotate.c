/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:36 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:08:09 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a, t_list **b)
{
	(void)b;
	ft_lstadd_back(a, ft_lstnew((*a)->content));
	ft_lstdelnode_by_value(a, (*a)->content, delete);
}

void	rb(t_list **a, t_list **b)
{
	(void)a;
	ft_lstadd_back(b, ft_lstnew((*b)->content));
	ft_lstdelnode_by_value(b, (*b)->content, delete);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, b);
	rb(a, b);
}

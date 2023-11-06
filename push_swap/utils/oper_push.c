/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:53 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:07:22 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	if (ft_lstsize(*b) <= 0)
		return ;
	ft_lstadd_front(a, ft_lstnew((*b)->content));
	ft_lstdelnode_by_value(b, (*b)->content, delete);
}

void	pb(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 0)
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	ft_lstdelnode_by_value(a, (*a)->content, delete);
}

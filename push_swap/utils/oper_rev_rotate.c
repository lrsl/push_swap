/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:45 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:07:39 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **a, t_list **b)
{
	t_list	*last;

	(void)b;
	last = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(last->content));
	ft_lstdelnode_by_address(a, last, delete);
}

void	rrb(t_list **a, t_list **b)
{
	t_list	*last;

	(void)a;
	last = ft_lstlast(*b);
	ft_lstadd_front(b, ft_lstnew(last->content));
	ft_lstdelnode_by_address(b, last, delete);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, b);
	rrb(a, b);
}

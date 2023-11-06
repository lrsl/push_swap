/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:21:48 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:08:55 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	compare(void *a, void *b)
{
	int	aa;
	int	bb;

	aa = *(int *)a;
	bb = *(int *)b;
	if (aa < bb)
		return (-1);
	else if (aa > bb)
		return (1);
	else
		return (0);
}

void	delete(void *content)
{
	int	a;

	a = *(int *)content;
}

static void	set_easy_index(t_list *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		*(int *)(lst->content) = i++;
		lst = lst->next;
	}
}

t_list	*initialize_stack(int *src, long int len)
{
	t_list		*stack;
	long int	i;
	t_list		*order;

	i = 0;
	stack = NULL;
	while (src && i < len)
		ft_lstadd_back(&stack, ft_lstnew(&src[i++]));
	if (!src || !len)
		stack = ft_lstnew(NULL);
	order = ft_lstsort(stack, compare, delete);
	set_easy_index(order);
	ft_lstclear(&order, delete);
	return (stack);
}

void	clear_stack(t_list *lst)
{
	return (ft_lstclear(&lst, &delete));
}

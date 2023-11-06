/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:58:52 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 13:58:52 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst -> content));
		if (!new)
		{
			ft_lstclear(&begin, del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}

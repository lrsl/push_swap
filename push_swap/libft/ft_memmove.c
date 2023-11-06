/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:31 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 13:59:31 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:01:23 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:01:23 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!little[0])
		return ((char *)&big[0]);
	if (!len)
		return (NULL);
	i = -1;
	while (big[++i] && i < len)
	{
		if (big[i] != little[0])
			continue ;
		k = i;
		j = 0;
		while (little[j] && little[j] == big[k] && k < len)
		{
			k++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
	}
	return (0);
}

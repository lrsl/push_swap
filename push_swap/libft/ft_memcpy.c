/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:26 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 13:59:26 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_arr;
	unsigned char	*src_arr;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	dest_arr = (unsigned char *)dest;
	src_arr = (unsigned char *)src;
	while (n--)
		*dest_arr++ = *src_arr++;
	return (dest);
}

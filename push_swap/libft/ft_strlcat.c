/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:51 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:51 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = -1;
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	while (size - 1 > len_dst + ++i && src[i])
		dst[len_dst + i] = src[i];
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}

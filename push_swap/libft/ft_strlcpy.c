/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:57 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:57 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = -1;
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (len);
}

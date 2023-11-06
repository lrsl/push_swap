/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:01:45 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:01:45 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;
	unsigned int	size;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	i = 0;
	while (i < start && s[i])
		i++;
	size = 0;
	while (size + i < start + len && s[size + i])
		size++;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < start + len && s[i])
	{
		new[i - start] = s[i];
		i++;
	}
	new[size] = '\0';
	return (new);
}

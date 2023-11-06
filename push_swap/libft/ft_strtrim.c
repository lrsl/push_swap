/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:01:39 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:01:39 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	is_set(const char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	int				prefix_len;
	int				suffix_len;
	unsigned int	size;

	prefix_len = 0;
	while (s1[prefix_len] && is_set(s1[prefix_len], set))
		prefix_len++;
	suffix_len = ft_strlen(s1);
	if (prefix_len == suffix_len)
	{
		new = (char *)malloc(1);
		new[0] = '\0';
		return (new);
	}
	while (suffix_len > 0 && is_set(s1[suffix_len - 1], set))
		suffix_len--;
	size = suffix_len - prefix_len;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (prefix_len <= suffix_len)
		*new ++ = s1[prefix_len++];
	*--new = '\0';
	return (new - size);
}

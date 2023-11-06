/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:33 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:33 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}

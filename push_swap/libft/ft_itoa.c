/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:56:44 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 13:56:44 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	get_number_len(int n)
{
	int	len;

	if (n == -2147483648)
		return (11);
	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	long int	ln;

	ln = (long int)n;
	len = get_number_len(ln);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (ln == 0)
		result[0] = '0';
	if (ln < 0)
	{
		result[0] = '-';
		ln = -ln;
	}
	result[len] = '\0';
	while (ln > 0)
	{
		result[--len] = ln % 10 + 48;
		ln /= 10;
	}
	return (result);
}

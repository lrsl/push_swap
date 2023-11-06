/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:20 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:20 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*my_free(char **sentence, int index)
{
	while (index >= 0)
		free(sentence[index++]);
	return (NULL);
}

static int	is_separator(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	word_counter(const char *s, const char c)
{
	int	words;

	words = 0;
	while (s && *s && is_separator(*s, c))
		s++;
	if (s && *s && !is_separator(*s, c))
		words++;
	while (s && *s && !is_separator(*s, c))
		s++;
	if (s && *s && is_separator(*s, c))
		words += word_counter(s, c);
	return (words);
}

static int	char_counter(const char *s, char c)
{
	int	letter;

	letter = 0;
	while (s[letter] && !is_separator(s[letter], c))
		letter++;
	return (letter);
}

char	**ft_split(char const *s, char c)
{
	int		nbr_word;
	char	**sentence;
	int		i;
	int		y;

	nbr_word = word_counter(s, c);
	sentence = (char **)malloc((nbr_word + 1) * sizeof(char *));
	if (!sentence)
		return (NULL);
	i = -1;
	while (++i < nbr_word)
	{
		while (is_separator(*s, c))
			s++;
		sentence[i] = malloc((char_counter(s, c) + 1) * sizeof(char));
		if (!sentence[i])
			return (my_free(sentence, i));
		y = 0;
		while (*s && !is_separator(*s, c))
			sentence[i][y++] = *s++;
		sentence[i][y] = '\0';
	}
	sentence[i] = 0;
	return (sentence);
}

/*int	main(int ac, char **av)
{
	char	**sentence;
	(void) ac;
	sentence = ft_split(av[1], ' ');
	for(int i = 0; sentence[i]; i++)
		printf("%s\n", sentence[i]);
	for(int i = 0; sentence[i]; i++)
		free(sentence[i]);
	free(sentence);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/16 12:27:45 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	find_words(const char str, char c)
{
	if (str == c || str == '\0')
		return (false);
	return (true);
}

static bool	free_all(char **res, size_t word)
{
	while (word)
		free(res[word--]);
	free(res);
	return (false);
}

static size_t	count_letters(const char *str, char c, size_t *start)
{
	size_t	letter;

	letter = 0;
	while (!find_words(str[*start], c) && str[*start] != '\0')
		(*start)++;
	while (find_words(str[*start + letter], c))
		letter++;
	return (letter);
}

static bool	cut_str(char **res, const char *str, char c)
{
	size_t	start;
	size_t	letter;
	size_t	word;

	start = 0;
	word = 0;
	while (str[start] != '\0')
	{
		letter = count_letters(str, c, &start);
		if (letter > 0)
		{
			res[word] = ft_substr(str, start, letter);
			if (!res[word])
				return (free_all(res, word));
			start += letter;
			word++;
		}
	}
	res[word] = NULL;
	return (true);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	count_words;
	size_t	i;

	count_words = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (find_words(s[i], c) && !find_words(s[i + 1], c))
			count_words++;
		i++;
	}
	res = (char **)ft_calloc(count_words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (!cut_str(res, s, c))
		return (NULL);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:38:14 by kthucydi          #+#    #+#             */
/*   Updated: 2022/06/27 10:54:39 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*leak(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static char	**fill(char const *s, int words, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		splitted[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (splitted[i] == NULL)
			return (leak(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *s++;
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		splitted = (char **)malloc(sizeof(char *) * 2);
		splitted[0] = ft_strdup("");
		splitted[1] = NULL;
		return (splitted);
	}
	words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (splitted == NULL)
		return (NULL);
	splitted = fill(s, words, c, splitted);
	return (splitted);
}

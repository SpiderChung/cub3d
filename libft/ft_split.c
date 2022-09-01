/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:58:47 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 17:33:44 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_split
 * Description: Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting ’s’ using the character ’c’ as a delimiter.  The
 * array must be ended by a NULL pointer.
 * Parameters: #1. The string to be split. #2. The delimiter character.
 * Return value: The array of new strings resulting from the split. NULL if
 * the allocation fails.													  */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_word_len(char const *s, char c)
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

static void	*ft_alloc_err(char **new_arr, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(new_arr[i]);
		i++;
	}
	free(new_arr);
	return (NULL);
}

static char	**ft_fill_array(char const *s, char c, int words, char **new_arr)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = ft_word_len(s, c);
		new_arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (new_arr[i] == NULL)
			return (ft_alloc_err(new_arr, i));
		j = 0;
		while (j < len)
			new_arr[i][j++] = *s++;
		new_arr[i][j] = '\0';
	}
	new_arr[i] = NULL;
	return (new_arr);
}

char	**ft_split(char	const *s, char c)
{
	char	**new_arr;
	int		word_cnt;

	if (!s)
		return (NULL);
	word_cnt = ft_count_words(s, c);
	new_arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (new_arr == NULL)
		return (NULL);
	new_arr = ft_fill_array(s, c, word_cnt, new_arr);
	return (new_arr);
}

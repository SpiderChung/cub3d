/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:58:25 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 15:01:12 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_strtrim
 * Description: Allocates (with malloc(3)) and returns a copy of ’s1’ with
 * the characters specified in ’set’ removed from the beginning and the end
 * of the string.
 * Parameters: #1. The string to be trimmed. #2. The reference set of
 * characters to trim.
 * Return value: The trimmed string.  NULL if the allocation fails.*/

#include "libft.h"

static int	ft_check_chrstr(char chr, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == chr)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check_chrstr(s1[start], set))
		start++;
	while (start < end && ft_check_chrstr(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}

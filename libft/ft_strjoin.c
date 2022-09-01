/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:58:10 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/19 18:38:04 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_strjoin
 * Description: Allocates (with malloc(3)) and returns a new string, which is
 * the result of the concatenation of ’s1’ and ’s2’.
 * Return value: The new string.  NULL if the allocation fails.
 * Parameters: #1. The prefix string. #2. The suffix string.				  */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (s2 && !s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str + len_s1, s2, len_s2 + 1);
	return (str);
}

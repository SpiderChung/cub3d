/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:31:32 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 16:59:02 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strchr                                               */
/* man strchr                                                                 */
/*The strchr() function locates the first occurrence of c in the string 	  */
/* pointed to by s.															  */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

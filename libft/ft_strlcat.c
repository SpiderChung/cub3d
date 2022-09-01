/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:40:29 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 16:58:18 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strlcat                                              */
/* man strlcat                                                                */
/* size-bounded string concatenation										  */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	l;

	l = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (l);
	while (*dst && dstsize)
	{
		dst++;
		i++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (l + i);
}

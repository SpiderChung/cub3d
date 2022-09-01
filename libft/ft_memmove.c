/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:22:08 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 16:11:15 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions memmove                                              */
/* man memmove                                                                */
/* The memmove() function copies len bytes from string src to string dst.	  */
/* The two strings may overlap; the copy is always done in a non-destructive  */
/* manner.																	  */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dst + (len - 1);
		s = (unsigned char *)src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

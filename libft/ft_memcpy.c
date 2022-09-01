/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:20:05 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 16:04:30 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions memcpy                                               */
/* man memcpy                                                                 */
/* The memcpy() function copies n bytes from memory area src to memory area   */
/* dst.  If dst and src overlap, behavior is undefined.  Applications in which*/
/* dst and src might overlap should use memmove(3) instead.					  */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!(dst || src))
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

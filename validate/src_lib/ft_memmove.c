/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:31:22 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/13 15:09:25 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*str;
	const unsigned char	*str2;

	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (dest <= src)
		ft_memcpy(dest, (void *)src, n);
	else
	{
		str = dest + n - 1;
		str2 = src + n - 1;
		while (n--)
		{
			str[i] = str2[i];
			i--;
		}
	}
	return (dest);
}

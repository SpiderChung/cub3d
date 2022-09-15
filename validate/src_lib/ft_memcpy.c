/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:30:37 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/15 13:22:40 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;
	int		i;

	if (!(dst || src))
		return (NULL);
	dest = dst;
	sourc = (void *)src;
	i = 0;
	while (n > 0)
	{
		dest[i] = sourc[i];
		i++;
		n--;
	}
	return (dst);
}

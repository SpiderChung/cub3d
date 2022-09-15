/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:36:23 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/13 16:32:00 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	l;
	int		i;

	l = ft_strlen(src);
	i = 0;
	if (!n)
		return (l);
	while (*dst && n)
	{
		dst++;
		i++;
		n--;
	}
	while (*src && n > 1)
	{
		*dst++ = *src++;
		n--;
	}
	if (n != 0)
	{
		*dst = '\0';
	}
	return (l + i);
}

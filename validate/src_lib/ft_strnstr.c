/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:44:56 by kthucydi          #+#    #+#             */
/*   Updated: 2022/06/17 22:32:51 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		i2;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		i2 = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + i2] == needle[i2] && needle[i2] != '\0'
				&& (size_t)(i + i2) < len)
				i2++;
			if (needle[i2] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:05:44 by kthucydi          #+#    #+#             */
/*   Updated: 2022/06/16 12:37:07 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrevdup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	if (n == 0)
	{
		return (NULL);
	}
	str = (char *)malloc(n + 1);
	if (str)
	{
		i = 0;
		while (i < n)
		{
			str[n - i - 1] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	buf[16];
	int		i;
	int		neg;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	i = 0;
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (n != 0 || i == 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		buf[i++] = '-';
	return (ft_strrevdup(buf, i));
}

char	*ftfirst_itoa(int n)
{
	int		k;	
	int		i;
	char	*dest;
	char	temp[40];

	k = n;
	i = 0;
	while ((k % 10 != 0) && (k / 10 != 0))
	{
		temp[i++] = (k % 10) + 48;
		k = k / 10;
	}
	if (n < 0)
		temp[i++] = '-';
	dest = malloc(i);
	if (dest == NULL)
		return (NULL);
	i--;
	while (i >= 0)
		dest[k++] = temp[i--];
	dest[k] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:59:09 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/19 18:35:03 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_itoa
 * Description: Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled.
 * Parameters: #1. the integer to convert.
 * Return value: The string representing the integer.  NULL if the allocation
 * fails.																	  */

#include "libft.h"

static int	ft_cnt_symbol(long int num)
{
	int	length;

	if (num <= 0)
		length = 1;
	else
		length = 0;
	while (num != 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

static int	ft_abc(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_cnt_symbol(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + ft_abc(n % 10);
		n = ft_abc(n / 10);
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:59:42 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:54:42 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_striteri
 * Description:Applies the function f to each character of the string passed
 * as argument, and passing its index as first argument.  Each character is
 * passed by address to f to be modified if necessary
 * Parameters: #1. The string on which to iterate. #2. The function to apply
 * to each character.
 * Return value: None.					 									  */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

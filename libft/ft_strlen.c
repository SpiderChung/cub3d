/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:46:28 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/11 13:46:43 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strlen                                               */
/* man strlen                                                                 */
/* The strlen() function computes the length of the string s.				  */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

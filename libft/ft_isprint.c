/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:39:43 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/06 19:42:40 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions isprint                                              */
/* man isprint                                                                */
/* The isprint() function tests for any printing character, including space.  */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

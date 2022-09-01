/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:37:58 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/06 19:39:28 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions isdigit                                              */
/* man isdigit                                                                */
/* The isdigit() function tests for a decimal digit character.				  */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

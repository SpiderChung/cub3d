/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:54:44 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 17:20:00 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions calloc                                               */
/* man calloc                                                                 */
/* Memory allocation 														  */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(count * size);
	if (NULL == dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}

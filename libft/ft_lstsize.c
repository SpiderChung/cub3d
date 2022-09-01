/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:58 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:49:05 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstsize
 * Description: Counts the number of elements in a list.
 * Parameters: #1. The beginning of the list.
 * Return value: Length of the list.										  */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}

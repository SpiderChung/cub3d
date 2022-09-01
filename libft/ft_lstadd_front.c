/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:46:52 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 17:47:34 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstadd_front
 * Description: Adds the element ’new’ at the beginning of the list.
 * Parameters: #1. The address of a pointer to the first link of a list.
 * #2. The address of a pointer to the element to be added to the list.
 * Return value: None														  */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && new)
		new->next = *lst;
	*lst = new;
}

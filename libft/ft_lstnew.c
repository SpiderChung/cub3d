/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:24 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:48:28 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstnew
 * Description: Allocates (with malloc(3)) and returns a new element. The
 * variable ’content’ is initialized with the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * Parameters: #1. The content to create the new element with.
 * Return value: The new element.											  */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (NULL == lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:22 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 18:17:50 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstdelone
 * Description: Takes as a parameter an element and frees the memory of the 
 * element’s content using the function ’del’ given as a parameter and free 
 * the element. The memory of ’next’ must not be freed.
 * Parameters: #1. The element to free. #2. The address of the function used 
 * to delete the content.
 * Return value: None														  */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}

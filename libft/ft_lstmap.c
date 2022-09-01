/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:37:17 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/19 18:37:20 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstmap
 * Description: Iterates the list ’lst’ and applies the function ’f’ to the
 * content of each element. Creates a new list resulting of the successive
 * applications of the function ’f’. The ’del’ function is used to delete the
 * content of an element if needed.
 * Parameters: #1. The adress of a pointer to an element. #2. The adress of
 * the function used to iterate on the list. #3. The adress of the function
 * used to delete the content of an element if needed.
 * Return value: The new list.  NULL if the allocation fails.				  */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (lst && f)
	{
		while (lst)
		{
			tmp = ft_lstnew((*f)(lst->content));
			if (!tmp)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, tmp);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}

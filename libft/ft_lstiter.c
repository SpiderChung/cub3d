/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:36:47 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/19 18:36:51 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstiter
 * Description: Iterates the list ’lst’ and applies the function ’f’ to the
 * content of each element.
 * Parameters: #1. The adress of a pointer to an element. #2. The adress of
 * the function used to iterate on the list.
 * Return value: None														  */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

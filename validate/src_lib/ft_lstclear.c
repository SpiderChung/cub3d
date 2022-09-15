/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:10:17 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/13 13:23:38 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*ent;

	ent = *lst;
	while (ent)
	{
		tmp = ent->next;
		if (del)
			del(ent->content);
		free(ent);
		ent = tmp;
	}
	*lst = NULL;
}

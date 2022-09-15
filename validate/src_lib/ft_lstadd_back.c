/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:36:35 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/15 12:14:09 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			begin = ft_lstlast(*lst);
			begin->next = new;
		}
	}
}

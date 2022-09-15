/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:39:36 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/12 12:00:53 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = lst;
	while (begin)
	{
		i++;
		f(begin->content);
		begin = begin->next;
	}
}

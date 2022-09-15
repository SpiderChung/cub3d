/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:29:20 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/12 11:59:10 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = lst;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

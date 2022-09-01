/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:14 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:53:17 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_putstr_fd
 * Description: Outputs the string ’s’ to the given file descriptor.
 * Parameters: #1. The string to output. #2. The file descriptor on which to
 * write.
 * Return value: None														  */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}

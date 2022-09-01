/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:02 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:51:17 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_putchar_fd
 * Description: Outputs the character ’c’ to the given file descriptor.
 * Parameters: #1. The character to output. #2. The file descriptor on which
 * to write.
 * Return value: None														  */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

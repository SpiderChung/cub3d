/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:30 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:52:10 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_putendl_fd
 * Description: Outputs the string ’s’ to the given file descriptor, followed
 * by a newline.
 * Parameters: #1. The string to output. #2. The file descriptor on which to
 * write.
 * Return value: None									 					  */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

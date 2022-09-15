/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:35:52 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:35:52 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	error(char *str)
{
	write(2, str, strlen(str));
	write(2, "\n", 1);
	exit (1);
}

char	*get_file(int fd)
{
	char	*s;
	int		i;
	char	*res;

	s = (char *)malloc(10000);
	i = 0;
	while (read(fd, s + i, 1) > 0)
		i++;
	if (i > 0)
	{
		s[i] = '\0';
		res = ft_strdup(s);
		free(s);
		return (res);
	}
	free(s);
	return (NULL);
}

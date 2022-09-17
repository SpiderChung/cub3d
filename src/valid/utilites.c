/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:17:42 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:17:42 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	ft_str_trim(char **str)
{
	int	len;

	len = ft_strlen(*str);
	while ((*str)[--len] == ' ')
		(*str)[len - 1] = '\0';
	while ((*str)[0] == ' ')
	{
		len = 0;
		while ((*str)[++len] != '\0')
			(*str)[len - 1] = (*str)[len];
		(*str)[len - 1] = '\0';
	}
}

int	char_in_str(char c, char *str, int i)
{
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_str_array(t_arrays *ar)
{
	int	i;

	i = 0;
	while (ar->map[i] != NULL)
		i++;
	return (i);
}

int	ft_count_str(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] != '\0' )
	{
		if (str[i++] == '\n')
			res++;
	}
	return (res);
}

int	search_max_string(t_arrays *ar)
{
	int		i;
	size_t	len;
	size_t	tmp;

	i = -1;
	len = ft_strlen(ar->map[0]);
	while (++i < ar->map_height - 1)
	{
		tmp = ft_strlen(ar->map[i]);
		if (len < tmp)
			len = tmp;
	}
	return ((int)len);
}

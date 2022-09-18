/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:31:37 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:31:37 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	ft_prokrust(t_arrays *ar, int i)
{
	char	*ptr;

	i = -1;
	ptr = (char *)malloc((ar->map_width + 1) * sizeof(char));
	while (++i < ar->map_width)
		ptr[i] = ' ';
	ptr[i] = '\0';
	ft_memcpy(ptr, ar->map[ar->ii], ft_strlen(ar->map[ar->ii]));
	free (ar->map[ar->ii]);
	ar->map[ar->ii] = ptr;
}

void	map_normalize(t_arrays *ar)
{
	ar->ii = -1;
	while (++(ar->ii) < ar->map_height)
	{
		if ((int)ft_strlen(ar->map[ar->ii]) < ar->map_width)
			ft_prokrust(ar, ar->ii);
	}
}

int	check_map_quadro(t_arrays *ar)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(ar->map[0]);
	while (i < ar->map_height && ft_strlen(ar->map[i]) == len)
	{
		i++;
	}
	if (ar->map[++i] == NULL)
		return (0);
	return (1);
}

void	check_map(t_arrays *ar)
{
	ar->map_height = ft_count_str_array(ar);
	ar->map_width = search_max_string(ar);
	if (check_map_quadro(ar))
		map_normalize(ar);
	check_border(ar);
	check_map_in(ar);
	check_door(ar);
}

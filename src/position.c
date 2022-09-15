/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:50:26 by schung            #+#    #+#             */
/*   Updated: 2022/09/15 03:21:55 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	to_north(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = FOV;
	data->dir_x = -1;
	data->dir_y = 0;
}

void	to_south(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = -FOV;
	data->dir_x = 1;
	data->dir_y = 0;
}

void	to_west(t_data *data)
{
	data->plane_x = -FOV;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = -1;
}

void	to_east(t_data *data)
{
	data->plane_x = FOV;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = 1;
}

int	set_player_position(t_data *data, int x, int y, char c)
{
	data->p_x = x;
	data->p_y = y;
	if (c == 'N')
		to_north(data);
	else if (c == 'E')
		to_east(data);
	else if (c == 'W')
		to_west(data);
	else if (c == 'S')
		to_south(data);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:26:48 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 23:33:05 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_vert_door(t_data *data)
{
	int	x;

	x = data->door.open_vert[0];
	if (x == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_x <= (double)x - 0.3 || data->p_x >= (double)x + 1.3)
		{
			data->map->lines[data->door.open_vert[0]][data->door.open_vert[1]]
				= '2';
			data->door.open_vert[0] = -1;
			data->door.open_vert[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_vert_door(t_data *data)
{
	int	x;
	int	y;

	if (close_vert_door(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->dir_x > 0)
		y = (int)((data->p_x + data->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + data->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map->lines[y][x] == '2')
	{
		data->door.open_vert[0] = y;
		data->door.open_vert[1] = x;
		data->map->lines[y][x] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	close_horizone_door(t_data *data)
{
	int	y;

	y = data->door.open_hor[1];
	if (y == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_y <= (double)y - 0.3 || data->p_y >= (double)y + 1.3)
		{
			data->map->lines[data->door.open_hor[0]][data->door.open_hor[1]]
				= '2';
			data->door.open_hor[0] = -1;
			data->door.open_hor[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_horizone_door(t_data *data)
{
	int	x;
	int	y;

	if (close_horizone_door(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->dir_y > 0)
		y = (int)((data->p_y + data->dir_y * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y + data->dir_y * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map->lines[x][y] == '2')
	{
		data->door.open_hor[0] = x;
		data->door.open_hor[1] = y;
		data->map->lines[x][y] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

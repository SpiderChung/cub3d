/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:37:06 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 23:47:02 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	wall_in_front_y(t_data *data, double len)
{
	int			x;
	int			y;
	static int	timeout;

	if (data->dir_y > 0)
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (open_horizone_door(data) == EXIT_SUCCESS && ++timeout < 5)
	{
		close_horizone_door(data);
		return (true);
	}
	timeout = 0;
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_behind_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_left_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_y + WALL_DISTANCE);
	else
		y = (int)(data->p_y - WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_right_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_y - WALL_DISTANCE);
	else
		y = (int)(data->p_y + WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

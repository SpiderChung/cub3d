/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:54:53 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 23:38:03 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	wall_in_front_x(t_data *data, double len)
{
	int			x;
	int			y;
	static int	timeout;

	if (data->dir_x > 0)
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (open_vert_door(data) == EXIT_SUCCESS && ++timeout < 5)
	{
		close_vert_door(data);
		return (true);
	}
	timeout = 0;
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_behind_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_left_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_x - WALL_DISTANCE);
	else
		y = (int)(data->p_x + WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_right_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_x + WALL_DISTANCE);
	else
		y = (int)(data->p_x - WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

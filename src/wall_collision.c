/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:54:53 by schung            #+#    #+#             */
/*   Updated: 2022/09/14 18:53:04 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	wall_in_front_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map.map[y][x] == '0')
		return	(false);
	return (true);
}

int wall_in_front_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map.map[x][y] == '0')
		return	(false);
	return (true);
}

int	wall_behind_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map.map[y][x] == '0')
		return	(false);
	return (true);
}

int wall_behind_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map.map[x][y] == '0')
		return	(false);
	return (true);
}

int	wall_left_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_x - WALL_DISTANCE);
	else
		y = (int)(data->p_x + WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map.map[y][x] == '0')
		return	(false);
	return (true);
}

int wall_left_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_y + WALL_DISTANCE);
	else
		y = (int)(data->p_y - WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map.map[x][y] == '0')
		return	(false);
	return (true);
}

int	wall_right_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_x + WALL_DISTANCE);
	else
		y = (int)(data->p_x - WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map.map[y][x] == '0')
		return	(false);
	return (true);
}

int wall_right_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_y - WALL_DISTANCE);
	else
		y = (int)(data->p_y + WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map.map[x][y] == '0')
		return	(false);
	return (true);
}

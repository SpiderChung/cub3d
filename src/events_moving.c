/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:41:11 by schung            #+#    #+#             */
/*   Updated: 2022/09/18 00:13:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	moving_straight(int keycode, t_data *data, double len)
{
	if (keycode == MOVE_UP)
	{
		if (wall_in_front_x(data, len) == false)
			data->p_x += (data->dir_x) / len * SPEED;
		if (wall_in_front_y(data, len) == false)
			data->p_y += (data->dir_y) / len * SPEED;
	}
	if (keycode == MOVE_DOWN)
	{
		if (wall_behind_x(data, len) == false)
			data->p_x += (-data->dir_x) / len * SPEED;
		if (wall_behind_y(data, len) == false)
			data->p_y += (-data->dir_y) / len * SPEED;
	}
}

static void	rotation_left(int keycode, t_data *data, double len)
{
	double	old_dir;
	double	old_plane;

	if (keycode == ROTATE_LEFT)
	{
		old_dir = data->dir_x;
		data->dir_x = cos(-ROTATE_SPEED) * data->dir_x
			- sin(-ROTATE_SPEED) * data->dir_y;
		data->dir_y = sin(-ROTATE_SPEED) * old_dir
			+ cos(-ROTATE_SPEED) * data->dir_y;
		old_plane = data->plane_x;
		data->plane_x = cos(-ROTATE_SPEED) * data->plane_x
			- sin(-ROTATE_SPEED) * data->plane_y;
		data->plane_y = sin(-ROTATE_SPEED) * old_plane
			+ cos(-ROTATE_SPEED) * data->plane_y;
		data->dir_x /= len;
		data->dir_y /= len;
	}
}

static void	rotation(int keycode, t_data *data, double len)
{
	double	old_dir;
	double	old_plane;

	if (keycode == ROTATE_RIGHT)
	{
		old_dir = data->dir_x;
		data->dir_x = cos(ROTATE_SPEED) * data->dir_x
			- sin(ROTATE_SPEED) * data->dir_y;
		data->dir_y = sin(ROTATE_SPEED) * old_dir
			+ cos(ROTATE_SPEED) * data->dir_y;
		old_plane = data->plane_x;
		data->plane_x = cos(ROTATE_SPEED) * data->plane_x
			- sin(ROTATE_SPEED) * data->plane_y;
		data->plane_y = sin(ROTATE_SPEED) * old_plane
			+ cos(ROTATE_SPEED) * data->plane_y;
		data->dir_x /= len;
		data->dir_y /= len;
	}
	rotation_left(keycode, data, len);
}

void	redrawing(t_data *data, int keycode)
{
	double	len;

	len = sqrt(data->dir_x * data->dir_x + data->dir_y * data->dir_y);
	if (keycode == ESCAPE)
		exit_game(data, EXIT_SUCCESS);
	if (keycode == MOVE_RIGHT)
	{
		if (wall_right_x(data, len) == false)
			data->p_x += (data->dir_y) / len * SPEED;
		if (wall_right_y(data, len) == false)
			data->p_y += (-data->dir_x) / len * SPEED;
	}
	if (keycode == MOVE_LEFT)
	{
		if (wall_left_x(data, len) == false)
			data->p_x += (-data->dir_y) / len * SPEED;
		if (wall_left_y(data, len) == false)
			data->p_y += (data->dir_x) / len * SPEED;
	}
	moving_straight(keycode, data, len);
	rotation(keycode, data, len);
}

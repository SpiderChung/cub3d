/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:50:48 by schung            #+#    #+#             */
/*   Updated: 2022/09/14 18:56:13 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_data *data, int exit_state)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (exit_state == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
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

int	mouse_hook(int x, int y, t_data *data)
{
	static int	previous;
	int 		current;

	current = x;
	(void)y;
	if (current > previous)
		redrawing(data, ROTATE_RIGHT);
	else if (current < previous)
		redrawing(data, ROTATE_LEFT);
	previous = current;
	return (EXIT_SUCCESS);
}

void	redrawing(t_data *data, int keycode)
{
	double len;

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
	rotation(keycode, data, len);
}

int	key_release(int key, t_data *data)
{
	if (key == MOVE_UP)
		data->controls.up = -1;
	else if (key == MOVE_DOWN)
		data->controls.down = -1;
	else if (key == MOVE_LEFT)
		data->controls.left = -1;
	else if (key == MOVE_RIGHT)
		data->controls.right = -1;
	else if (key == ROTATE_LEFT)
		data->controls.rotate_left = -1;
	else if (key == ROTATE_RIGHT)
		data->controls.rotate_right = -1;
	else if (key == ESCAPE)
		data->controls.escape = -1;
	return (EXIT_SUCCESS);
}

int	key_press(int keycode, t_data *data)
{
	{
	if (keycode == MOVE_UP)
		data->controls.up = MOVE_UP;
	else if (keycode == MOVE_DOWN)
		data->controls.down = MOVE_DOWN;
	else if (keycode == MOVE_LEFT)
		data->controls.left = MOVE_LEFT;
	else if (keycode == MOVE_RIGHT)
		data->controls.right = MOVE_RIGHT;
	else if (keycode == ROTATE_LEFT)
		data->controls.rotate_left = ROTATE_LEFT;
	else if (keycode == ROTATE_RIGHT)
		data->controls.rotate_right = ROTATE_RIGHT;
	else if (keycode == ESCAPE)
		data->controls.escape = ESCAPE;
	return (EXIT_SUCCESS);
}
}

void	check_events(t_data *data)
{
	int	*ptr;
	int	i;

	ptr = (int *)&data->controls;
	i = 0;
	while (i < 7)
	{
		if (*(ptr + i) > -1)
			redrawing(data, *(ptr + i));
		i++;
	}

	// if (data->controls.down == MOVE_DOWN)
	// 	redrawing(data, MOVE_DOWN);
	// if (data->controls.up == MOVE_UP)
	// 	redrawing(data, MOVE_UP);
	// if (data->controls.left == MOVE_LEFT)
	// 	redrawing(data, MOVE_LEFT);
	// if (data->controls.right == MOVE_RIGHT)
	// 	redrawing(data, MOVE_RIGHT);
	// if (data->controls.rotate_left == ROTATE_LEFT)
	// 	redrawing(data, ROTATE_LEFT);
	// if (data->controls.rotate_right == ROTATE_RIGHT)
	// 	redrawing(data, ROTATE_RIGHT);
	// if (data->controls.escape == ESCAPE)
	// 	redrawing(data, ESCAPE);
}

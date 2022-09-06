/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:50:48 by schung            #+#    #+#             */
/*   Updated: 2022/09/06 22:31:24 by schung           ###   ########.fr       */
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

int	key_release(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		data->controls.escape = -1;
	return (EXIT_SUCCESS);
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
		key_press(ROTATE_RIGHT, data);
	else if (current < previous)
		key_press(ROTATE_LEFT, data);
	previous = current;
	return (EXIT_SUCCESS);
}

int	key_press(int keycode, t_data *data)
{
	double	len;

	len = sqrt(data->dir_x * data->dir_x + data->dir_y * data->dir_y);
	if (keycode == ESCAPE)
		exit_game(data, EXIT_SUCCESS);
	if (keycode == MOVE_RIGHT)
	{
		data->p_x += (data->dir_y) / len * SPEEEEEED;
		data->p_y += (-data->dir_x) / len * SPEEEEEED;
	}
	if (keycode == MOVE_LEFT)
	{
		data->p_x += (-data->dir_y) / len * SPEEEEEED;
		data->p_y += (data->dir_x) / len * SPEEEEEED;
	}
	if (keycode == MOVE_UP)
	{
		data->p_x += (data->dir_x) / len * SPEEEEEED;
		data->p_y += (data->dir_y) / len * SPEEEEEED;
	}
	if (keycode == MOVE_DOWN)
	{
		data->p_x += (-data->dir_x) / len * SPEEEEEED;
		data->p_y += (-data->dir_y) / len * SPEEEEEED;
	}
	rotation(keycode, data, len);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:50:48 by schung            #+#    #+#             */
/*   Updated: 2022/09/02 11:17:29 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int exit_game(t_data *data, int exit_state)
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
	return(EXIT_SUCCESS);
}

int	key_press(int keycode, t_data *data)
{
	double len;


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
	if (keycode == ROTATE_RIGHT)
	{
		data->dir_x = cos(ROTATE_SPEED) * data->dir_x - sin(ROTATE_SPEED) * data->dir_y;
		data->dir_y = sin(ROTATE_SPEED) * data->dir_x + cos(ROTATE_SPEED) * data->dir_y;
		data->dir_x /= len;
		data->dir_y /= len;
	}
	if (keycode == ROTATE_LEFT)
	{
		data->dir_x = cos(-ROTATE_SPEED) * data->dir_x - sin(-ROTATE_SPEED) * data->dir_y;
		data->dir_y = sin(-ROTATE_SPEED) * data->dir_x + cos(-ROTATE_SPEED) * data->dir_y;
		data->dir_x /= len;
		data->dir_y /= len;
	}

	// while (data->point.y < HEIGHT)
	// {
	// 	my_mlx_pixel_put(&data->img, data->point.x, data->point.y, 0x00FF0000);
	// 	data->point.x = data->point.y/data->point.z;
	// 	data->point.y++;
	// }
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 200, 210);
	return (EXIT_SUCCESS);
}

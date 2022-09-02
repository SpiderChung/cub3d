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
	if (keycode == ESCAPE)
		exit_game(data, EXIT_SUCCESS);
	else if (keycode == MOVE_LEFT)
		data->point.z++;
	else if (keycode == MOVE_RIGHT)
		data->point.z--;
	while (data->point.y < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, data->point.x, data->point.y, 0x00FF0000);
		data->point.x = data->point.y/data->point.z;
		data->point.y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 200, 210);
	return (EXIT_SUCCESS);
}

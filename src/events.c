/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:50:48 by schung            #+#    #+#             */
/*   Updated: 2022/09/18 00:22:20 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_data *data, int exit_state)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_all(data);
	if (exit_state == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int x, int y, t_data *data)
{
	static int	previous;
	int			current;

	current = x;
	(void)y;
	if (current > previous)
		redrawing(data, ROTATE_RIGHT);
	else if (current < previous)
		redrawing(data, ROTATE_LEFT);
	previous = current;
	return (EXIT_SUCCESS);
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
}

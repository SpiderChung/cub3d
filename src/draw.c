/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:45:00 by schung            #+#    #+#             */
/*   Updated: 2022/09/18 01:57:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_ceiling(t_data *data, int x, int up_to)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	red = data->img.ceiling[0];
	green = data->img.ceiling[1];
	blue = data->img.ceiling[2];
	color = create_rgb(red, green, blue);
	i = 0;
	while (i < up_to && i < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
}

void	draw_floor(t_data *data, int x, int from)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	red = data->img.floor[0];
	green = data->img.floor[1];
	blue = data->img.floor[2];
	color = create_rgb(red, green, blue);
	i = from;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
}

int	draw_game(t_data *data)
{
	int	x;

	x = 0;
	check_events(data);
	usleep(5000);
	while (x < WIDTH)
	{
		get_ray(data, x);
		draw_walls(data, x);
		draw_ceiling(data, x, data->wall.top);
		draw_floor(data, x, data->wall.bottom);
		if (data->door.door)
			draw_doors(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	draw_shotgun(data);
	return (EXIT_SUCCESS);
}

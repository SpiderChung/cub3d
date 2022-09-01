/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:45:00 by schung            #+#    #+#             */
/*   Updated: 2022/09/01 20:48:25 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int draw_game(t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		get_ray(data, x);
		draw_walls(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	//mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (EXIT_SUCCESS);
}
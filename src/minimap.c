/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:14:51 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 04:36:51 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_25(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(img, (x * 5) + i, (y * 5) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = -1;
		while (j < 5)
		{
			my_mlx_pixel_put(&data->img, (data->p_y * 5) + i,
				(data->p_x * 5) + j, 0xDC1430);
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_data *data)
{
	int	rows;
	int	col;
	int	i;
	int	j;
	int	color;

	rows = data->map->heigth;
	col = data->map->width;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < col)
		{
			color = get_color(data->map->lines[j][i]);
			if (color)
				draw_25(&data->img, i, j, color);
			j++;
		}
		i++;
	}
	draw_player(data);
	return (0);
}

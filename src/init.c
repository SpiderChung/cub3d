/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:13:18 by schung            #+#    #+#             */
/*   Updated: 2022/09/02 11:53:53 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->textures.tex_addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	get_minimap_color(t_data *data, int x, int y)
{
	char	c;

	x = x - 10 + data->p_y;
	y = y - 10 + data->p_x;
	if (x < 0 || y < 0 || x >= data->map.rows || y >= data->map.columns)
		return (0x00D49B);
	c = data->map.map[y][x];
	if (c == '0')
		return (0xFFFFFF);
	else if (c == '1' || c == '3')
		return (0xD47015);
	else if (c == ' ' || c == '\0')
		return (0x0000FF);
	else
		return (0x00FF00);
}

int	get_color(char c)
{
	int	color;

	if (c == '0')
		color = 0x000000;
	else if (c == '2')
		color = 0x00FF00;
	else if (c == '1' || c == '3')
		color = 0x008000;
	else
		color = 0;
	return (color);
}
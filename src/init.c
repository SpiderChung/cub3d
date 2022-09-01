/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:13:18 by schung            #+#    #+#             */
/*   Updated: 2022/09/01 18:48:33 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	ft_putstr_fd(dst, 1);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:15:22 by schung            #+#    #+#             */
/*   Updated: 2022/09/01 18:26:35 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void get_textures(t_data *data)
{
	int		width;
	int		height;
	int		i;

	data->img.tex_path[east] = ft_strdup("textures/east.xpm");
	data->img.tex_path[west] = ft_strdup("textures/west.xpm");
	data->img.tex_path[north] = ft_strdup("textures/west.xpm");
	data->img.tex_path[south] = ft_strdup("textures/west.xpm");
	i = 0;
	while (i < 4)
	{
		data->img.textures.tex_ptr[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.tex_path[i], &width, &height);
		if (data->img.textures.tex_ptr[i] == NULL)
			write(2, "Memory alloc\n", 14);
		data->img.textures.tex_addr = mlx_get_data_addr(data->img.textures.tex_ptr[i],
				&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
		get_wall_pixels(data, i);
		i++;
	}
}

void	get_wall_pixels(t_data *data, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE_XPM)
	{
		j = 0;
		while (j < SIZE_XPM)
		{
			if (type == east)
				data->img.textures.east_wall[i][j] = my_mlx_pixel_get(&data->img, i, j);
			else if (type == north)
				data->img.textures.north_wall[i][j] = my_mlx_pixel_get(&data->img, i, j);
			else if (type == south)
				data->img.textures.south_wall[i][j] = my_mlx_pixel_get(&data->img, i, j);
			else if (type == west)
				data->img.textures.west_wall[i][j] = my_mlx_pixel_get(&data->img, i, j);
			j++;
		}
		i++;
	}
}
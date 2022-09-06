/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:15:22 by schung            #+#    #+#             */
/*   Updated: 2022/09/06 23:37:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	get_textures(t_data *data)
{
	int		width;
	int		height;
	int		i;
	t_img	*img;

	img = &data->img;
	img->tex_path[east] = ft_strdup("textures/east.xpm");
	img->tex_path[west] = ft_strdup("textures/mossy.xpm");
	img->tex_path[north] = ft_strdup("textures/north.xpm");
	img->tex_path[south] = ft_strdup("textures/south.xpm");
	i = 0;
	while (i < 4)
	{
		img->textures.tex_ptr[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.tex_path[i], &width, &height);
		if (data->img.textures.tex_ptr[i] == NULL)
			ft_putstr_fd("Failure of memory allocation\n", 2);
		img->textures.tex_addr = mlx_get_data_addr(img->textures.tex_ptr[i],
				&img->bits_per_pixel, &img->line_length, &img->endian);
		if (img->textures.tex_addr == NULL)
			return (EXIT_FAILURE);
		get_wall_pixels(img, i);
		free(img->textures.tex_addr);
		img->textures.tex_addr = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	get_wall_pixels(t_img *img, int type)
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
				img->textures.east_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == north)
				img->textures.north_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == south)
				img->textures.south_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == west)
				img->textures.west_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
			// if (type == east)
			// 	img->textures.east_wall[i][j] = 123;
			// else if (type == north)
			// 	img->textures.north_wall[i][j] = 123;
			// else if (type == south)
			// 	img->textures.south_wall[i][j] = 123;
			// else if (type == west)
			// 	img->textures.west_wall[i][j] = 123;
			// j++;
		}
		i++;
	}
}
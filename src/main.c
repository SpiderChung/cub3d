/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:26 by schung            #+#    #+#             */
/*   Updated: 2022/09/18 15:45:39 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_data(t_data *data, t_validate *val)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (data->mlx_win == NULL)
		return (EXIT_FAILURE);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img.img_ptr == NULL)
	{
		ft_putstr_fd("FAILURE_OF_Failure of creating image pointer\n", 2);
		exit_game(data, EXIT_FAILURE);
	}
	if (get_textures(data, val) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (data->img.addr == NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		ft_putstr_fd("Failure of creating image address\n", 2);
		exit_game(data, EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	init_door(t_door *door)
{
	door->door = false;
	door->open_vert[0] = -1;
	door->open_vert[1] = -1;
	door->open_hor[0] = -1;
	door->open_hor[1] = -1;
	door->perp_wall_dist = 0;
	door->x = 0;
	door->side = 0;
	door->dir_x = 0;
	door->dir_y = 0;
}

void	start_init(t_data *data)
{
	int	i;

	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	ft_memset(&(data->controls), -1, sizeof(t_controls));
	i = 0;
	while (i < 5)
		data->img.tex_path[i++] = NULL;
	i = 0;
	while (i < 5)
		data->img.textures.tex_ptr[i++] = NULL;
	init_door(&(data->door));
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_validate	*val;
	int			i;

	start_init(&data);
	val = validate(argv, argc);
	data.map = &(val->map);
	set_player_position(&data, &(val->hero));
	i = 0;
	while (i++ < 3)
	{
		data.img.floor[i] = val->colors.floor[i];
		data.img.ceiling[i] = val->colors.ceiling[i];
	}
	if (init_data(&data, val) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_texture_paths(&(data.img));
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_game, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	exit(EXIT_SUCCESS);
}

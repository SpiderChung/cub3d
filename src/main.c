/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:26 by schung            #+#    #+#             */
/*   Updated: 2022/09/02 15:10:56 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_data(t_data *data)
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
		ft_putstr_fd("Failure of creating image pointer\n", 2);
		exit_game(data, EXIT_FAILURE);
	}
	get_textures(data);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (data->img.addr == NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		ft_putstr_fd("Failure of creating image address\n", 2);
		exit_game(data, EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	set_player_position(t_data *data)
{
	data->plane_x = -0.76;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = 1;
}

void	start_init(t_data *data)
{
	int i;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	i = 0;
	while (i < 4)
		data->img.tex_path[i++] = NULL;
	i = 0;
	while (i < 4)
	 	data->img.textures.tex_ptr[i++] = NULL;

}

int main(int argc, char **argv)
{
	t_data	data;
	start_init(&data);
	char 	map[20][20] = {	"11111111111111111111",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000011100001",
							"10000000000010100001",
							"10000000000011100001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
							"11111111111111111111"};

	data.map.map = (char **)ft_calloc(21, sizeof(char *));
	int i = 0;
	while (i < 20)
	{
		data.map.map[i] = (char *)ft_calloc(20, sizeof(char));
		data.map.map[i] = map[i];
		i++;
 	}
	data.map.columns = 20;
	data.map.rows = 20;
	// i = 0;
	// int j;
	// while (i < SIZE_XPM) 
	// {
	// 	j = 0;
	// 	while (j < SIZE_XPM)
	// 	{
	// 		ft_putnbr_fd(data.img.textures.east_wall[i][j], 1);
	// 		ft_putstr_fd(" ", 1);
	// 		j++;
	// 	}
	// 	ft_putstr_fd("\n", 1);
	// 	i++;
	// }
	if (!argv)
		printf("Hello");
	if (argc != 2 && write(2, "Wrong number of arguments!\n", 28))
		return (EXIT_FAILURE);
	if (init_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data.p_x = 4;
	data.p_y = 10;
	set_player_position(&data);
	//mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.textures.tex_ptr[east], 0, 0);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	//mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	//mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_loop(data.mlx_ptr);
	exit(EXIT_SUCCESS);
}

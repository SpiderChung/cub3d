/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:26 by schung            #+#    #+#             */
/*   Updated: 2022/09/01 20:55:46 by schung           ###   ########.fr       */
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
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	return (EXIT_SUCCESS);
}


void	start_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
}

int main(int argc, char **argv)
{
	t_data	data;
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
							"10000000000000000001",
							"10000000000000000001",
							"10000000000000000001",
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
	if (!argv)
		printf("Hello");
	if (argc != 2 && write(2, "Wrong number of arguments!\n", 28))
		return (EXIT_FAILURE);
	
	
	init_data(&data);
	data.p_x = 10;
	data.p_y = 15;
	get_textures(&data);
	//get_textures(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.textures.tex_ptr[east], 0, 0);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	//mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	//mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_loop(data.mlx_ptr);
	exit(EXIT_SUCCESS);
}

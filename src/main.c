/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:26 by schung            #+#    #+#             */
/*   Updated: 2022/09/01 20:11:43 by schung           ###   ########.fr       */
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
	char 	map[10][10] = {	"1111111111",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1111111111"};

	data.map.map = (char **)ft_calloc(11, sizeof(char *));
	int i = 0;
	while (i < 10)
	{
		data.map.map[i] = (char *)ft_calloc(10, sizeof(char));
		data.map.map[i] = map[i];
		i++;
 	}
	if (!argv)
		printf("Hello");
	if (argc != 2 && write(2, "Wrong number of arguments!\n", 28))
		return (EXIT_FAILURE);
	
	
	init_data(&data);
	data.p_x = 5;
	data.p_y = 5;
	printf("__%f____%f__\n", data.p_x, data.p_y);
	get_textures(&data);
	//get_textures(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.textures.tex_ptr[east], 500, 100);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	//mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	//mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_loop(data.mlx_ptr);
	exit(EXIT_SUCCESS);
}

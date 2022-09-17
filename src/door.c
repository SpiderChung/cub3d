/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:39:45 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 23:33:15 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_door_data(t_data *data, t_door *door)
{
	t_wall	*wall;
	int		line_height;
	double	hit_point;

	wall = &data->wall;
	line_height = (int)(HEIGHT / door->perp_wall_dist);
	wall->top = -line_height / 2 + HEIGHT / 2;
	if (wall->top < 0)
		wall->top = 0;
	wall->bottom = line_height / 2 + HEIGHT / 2;
	if (wall->bottom >= HEIGHT)
		wall->bottom = HEIGHT - 1;
	if (door->side == 0)
		hit_point = data->p_y + door->perp_wall_dist * door->dir_y;
	else
		hit_point = data->p_x + door->perp_wall_dist * door->dir_x;
	hit_point -= floor((hit_point));
	wall->x = (int)(hit_point * (double)(SIZE_XPM));
	if ((door->side == 0 && door->dir_x > 0)
		|| (door->side == 1 && door->dir_y < 0))
		wall->x = SIZE_XPM - wall->x - 1;
	wall->step = (1.0 * SIZE_XPM / line_height);
	wall->position = (wall->top - 0 - HEIGHT / 2
			+ line_height / 2) * wall->step;
}

void	draw_doors(t_data *data, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	get_door_data(data, &data->door);
	y = data->wall.top;
	while (y < data->wall.bottom)
	{
		wall_y = (int)data->wall.position & (SIZE_XPM - 1);
		data->wall.position += data->wall.step;
		pixel = data->img.textures.doors[data->wall.x][wall_y];
		my_mlx_pixel_put(&data->img, x, y, pixel);
		y++;
	}
}

void	set_door_data(t_data *data, int x)
{
	data->door.door = true;
	data->door.perp_wall_dist = get_perp_wall_dist(data);
	data->door.x = x;
	data->door.side = data->ray.side;
	data->door.dir_x = data->ray.dir_x;
	data->door.dir_y = data->ray.dir_y;
}

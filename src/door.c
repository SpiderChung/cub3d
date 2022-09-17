/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:39:45 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 00:42:38 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_vert_door(t_data *data)
{
	int	x;

	x = data->door.open_vert[0];
	if (x == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_x <= (double)x - 0.3 || data->p_x >= (double)x + 1.3)
		{
			data->map.lines[data->door.open_vert[0]][data->door.open_vert[1]]
				= '2';
			data->door.open_vert[0] = -1;
			data->door.open_vert[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_vert_door(t_data *data)
{
	int	x;
	int	y;

	if (close_vert_door(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->dir_x > 0)
		y = (int)((data->p_x + data->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + data->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map.lines[y][x] == '2')
	{
		data->door.open_vert[0] = y;
		data->door.open_vert[1] = x;
		data->map.lines[y][x] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	close_horizone_door(t_data *data)
{
	int	y;

	y = data->door.open_hor[1];
	if (y == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_y <= (double)y - 0.3 || data->p_y >= (double)y + 1.3)
		{
			data->map.lines[data->door.open_hor[0]][data->door.open_hor[1]]
				= '2';
			data->door.open_hor[0] = -1;
			data->door.open_hor[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_horizone_door(t_data *data)
{
	int	x;
	int	y;

	if (close_horizone_door(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->dir_y > 0)
		y = (int)((data->p_y + data->dir_y * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y + data->dir_y * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map.lines[x][y] == '2')
	{
		data->door.open_hor[0] = x;
		data->door.open_hor[1] = y;
		data->map.lines[y][x] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

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

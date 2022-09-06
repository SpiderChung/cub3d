/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:43:59 by schung            #+#    #+#             */
/*   Updated: 2022/09/06 22:45:19 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	get_pixel(t_wall *wall, t_img *img, int y)
{
	int	pixel;

	if (wall->direction == east)
		pixel = img->textures.east_wall[wall->x][y];
	else if (wall->direction == north)
		pixel = img->textures.north_wall[wall->x][y];
	else if (wall->direction == west)
		pixel = img->textures.west_wall[wall->x][y];
	else
		pixel = img->textures.south_wall[wall->x][y];
	return (pixel);
}

void	draw_walls(t_data *data, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	get_wall(data);
	y = data->wall.top;
	while (y < data->wall.bottom)
	{
		wall_y = (int)data->wall.position & (SIZE_XPM - 1);
		data->wall.position += data->wall.step;
		pixel = get_pixel(&data->wall, &data->img, wall_y);
		my_mlx_pixel_put(&data->img, x, y, pixel);
		y++;
	}
}

void	get_wall(t_data *data)
{
	t_wall	*wall;
	int		line_height;
	double	wall_x;

	wall = &data->wall;
	line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
	wall->top = -line_height / 2 + HEIGHT / 2;
	if (wall->top < 0)
		wall->top = 0;
	wall->bottom = line_height / 2 + HEIGHT / 2;
	if (wall->bottom >= HEIGHT)
		wall->bottom = HEIGHT - 1;
	if (data->ray.side == 0)
		wall_x = data->p_y + data->ray.perp_wall_dist * data->ray.dir_y;
	else
		wall_x = data->p_x + data->ray.perp_wall_dist * data->ray.dir_x;
	wall_x -= floor((wall_x));
	wall->x = (int)(wall_x * (double)(SIZE_XPM));
	if ((data->ray.side == 0 && data->ray.dir_x > 0)
		|| (data->ray.side == 1 && data->ray.dir_y < 0))
		wall->x = SIZE_XPM - wall->x - 1;
	wall->step = 1.0 * SIZE_XPM / line_height;
	wall->position
		= (wall->top - 0 - HEIGHT / 2 + line_height / 2) * wall->step;
}
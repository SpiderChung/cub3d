/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:39:50 by schung            #+#    #+#             */
/*   Updated: 2022/09/13 22:47:00 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void set_direction(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->p_x - (int)data->p_x) * ray->delta_x;
		data->wall.vertical = north;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)data->p_x + 1.0 - data->p_x) * ray->delta_x;
		data->wall.vertical = south;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->p_y - (int)data->p_y) * ray->delta_y;
		data->wall.horizontal = west;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)data->p_y + 1.0 - data->p_y) * ray->delta_y;
		data->wall.horizontal = east;
	}

}

bool	is_wall(t_data *data, int x, int y, int p_x)
{
	int i;

	i = p_x;
	i++;
	if (data->map.map[x][y] != '0' && data->map.map[x][y] != '2')
		return (true);
	return (false);
}

void	searching_wall(t_data *data, t_ray *ray, int p_x)
{
	int	wall;
	int x;
	int y;

	x = (int)data->p_x;
	y = (int)data->p_y;
	wall = false;
	while (wall == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			y += ray->step_y;
			ray->side = 1;
		}
		wall = is_wall(data, x, y, p_x);
	}
}

double	get_perp_wall_dist(t_data *data)
{
	t_ray	*ray;
	double	perp_wall_dist;

	ray = &data->ray;
	if (ray->side == 0)
	{
		data->wall.direction = data->wall.vertical;
		perp_wall_dist = ray->side_dist_x - ray->delta_x;
	}
	else
	{
		data->wall.direction = data->wall.horizontal;
		perp_wall_dist = ray->side_dist_y - ray->delta_y;
	}
	if (perp_wall_dist == 0)
	  	perp_wall_dist += 0.01;
	return (perp_wall_dist);
}

int get_ray(t_data *data, int x)
{
	t_ray	*ray;

	ray = &data->ray;
	ray->camera = 2 * x / (double)WIDTH - 1;
	ray->dir_x = data->dir_x + data->plane_x * ray->camera;
	ray->dir_y = data->dir_y + data->plane_y * ray->camera;
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)	
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	set_direction(data, &data->ray);
	searching_wall(data, &data->ray, x);
	ray->perp_wall_dist = get_perp_wall_dist(data);
	return (EXIT_SUCCESS);
}
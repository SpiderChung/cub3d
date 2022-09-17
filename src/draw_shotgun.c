/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shotgun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:37:31 by schung            #+#    #+#             */
/*   Updated: 2022/09/17 23:36:23 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	is_movement(t_data *data)
{
	return (data->controls.down != -1 || data->controls.up != -1
		|| data->controls.left != -1 || data->controls.right != -1);
}

void	draw_shotgun(t_data *data)
{
	static int	level;
	static bool	direction;

	if (level == -30)
		direction = true;
	else if (level == 30)
		direction = false;
	if (is_movement(data) == true && direction == true)
		level += 1;
	else if (is_movement(data) == true)
		level -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.textures.shotgun, 350, level + 50);
}

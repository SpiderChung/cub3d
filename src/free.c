/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:02:39 by schung            #+#    #+#             */
/*   Updated: 2022/09/18 00:21:57 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texture_paths(t_img *img)
{
	int	i;

	i = -1;
	while (img && ++i < 6)
	{
		if (img->tex_path[i] != NULL)
		{
			free(img->tex_path[i]);
			img->tex_path[i] = NULL;
		}
	}
}

char	*ft_free_array(char ***arr, unsigned int allocated)
{
	unsigned int	i;
	unsigned int	current;

	current = 1;
	if (*arr == NULL)
		return (NULL);
	i = 0;
	while (i < allocated + current)
	{
		if ((*arr)[i] != NULL)
		{
			free((*arr)[i]);
			(*arr)[i] = NULL;
		}
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

void	free_all(t_data *data)
{
	free_texture_paths(&data->img);
	ft_free_array(&data->map->lines, data->map->width);
}

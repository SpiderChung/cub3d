/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:37:59 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:37:59 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	validate_free(t_arrays *ar)
{
	free(ar->colors[0]);
	free(ar->colors[1]);
	free(ar->colors);
	free(ar->textures[0]);
	free(ar->textures[1]);
	free(ar->textures[2]);
	free(ar->textures[3]);
	free(ar->textures);
	ar->ii = -1;
	while (++(ar->ii) < ar->map_height)
		free(ar->map[ar->ii]);
	free(ar->map[ar->ii]);
	free(ar->map[ar->ii]);
	free(ar->map);
	free(ar->str);
}

t_validate	*validate_init(t_arrays *ar)
{
	t_validate	*val;

	val = malloc(sizeof(t_validate));
	ar->ii = -1;
	while (++(ar->ii) < 3)
	{
		val->colors.floor[ar->ii] = ar->f[ar->ii];
		val->colors.ceiling[ar->ii] = ar->c[ar->ii];
	}
	val->wall.no = ft_strdup(ar->textures[0]);
	val->wall.so = ft_strdup(ar->textures[1]);
	val->wall.we = ft_strdup(ar->textures[2]);
	val->wall.ea = ft_strdup(ar->textures[3]);
	val->map.width = ar->map_height;
	val->map.heigth = ar->map_width;
	val->map.lines = malloc(sizeof(char *) * (ar->map_height + 1));
	ar->ii = -1;
	while (++(ar->ii) < ar->map_height)
		val->map.lines[ar->ii] = ft_strdup(ar->map[ar->ii]);
	val->map.char_list = ft_strdup(MAP_CHAR);
	val->hero.direction = ar->direction;
	val->hero.x = ar->hpx;
	val->hero.y = ar->hpy;
	validate_free(ar);
	return (val);
}

t_validate	*validate(char **argv, int argc)
{
	t_arrays	arrays;
	int			fdmap;
	int			len;

	if (argc < 2 || argc > 2)
		error("ERROR: INCORRECT ARGUMENT'S QUANTITY");
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 1] == 'b' && argv[1][len - 2] == 'u'
		&& argv[1][len - 3] == 'c' && argv[1][len - 4] == '.'))
		error("ERROR: INVALID_EXTENSION_OF_MAP_FILE");
	fdmap = open(argv[1], O_RDONLY);
	if (fdmap < 0)
		error("ERROR: MAP_FILE_CAN'T_OPEN");
	arrays = read_file(fdmap);
	return (validate_init(&arrays));
}

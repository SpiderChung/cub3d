/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:05:58 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:05:58 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	init_check(t_arrays *ar, char *str, char *temp, int *i)
{
	if (char_in_str(temp[0], "FC", 0) && ar->flag_colors == 0)
	{
		init_colors(ar, str, i);
		check_colors(ar);
	}
	else if (char_in_str(temp[0], "NSWE", 0) && ar->flag_textures == 0)
	{
		init_textures(ar, str, i);
		check_textures(ar);
	}
	else if (char_in_str(temp[0], " 1", 0)
		&& ar->flag_textures == 4 && ar->flag_colors == 2)
	{
		init_map(ar, str, i);
		check_map(ar);
	}
	else
		error("ERROR: MAP_FILE_INCORRECT");
}

void	init_arrays(t_arrays *ar, char *str, int i)
{
	char		temp[3];
	int			k;

	while (str[i])
	{
		k = 0;
		while (str[i] != '\n' && k < 2)
			temp[k++] = str[i++];
		temp[k] = '\0';
		if (k != 0)
		{
			i -= 2;
			init_check(ar, str, temp, &i);
		}
		if (str[i])
			i++;
	}
}

void	initial_arrays(t_arrays *ar)
{
	int	i;

	i = -1;
	ar->colors = (char **)malloc(sizeof(char *) * 2);
	ar->textures = (char **)malloc(sizeof(char *) * 4);
	if (ar->colors == NULL || ar->textures == NULL)
		error("ERROR: INIT_ARRAY_MALLOC'S_ERROR");
	ar->colors[0] = NULL;
	ar->colors[1] = NULL;
	while (++i < 4)
		ar->textures[i] = NULL;
	ar->flag_colors = 0;
	ar->flag_textures = 0;
	ar->flag_hero = 0;
	ar->empty_string = 0;
}

t_arrays	read_file(int fdmap)
{
	char		*str;
	t_arrays	arrays;

	str = get_file(fdmap);
	if (!str)
		error("EMPTY_MAP_FILE");
	initial_arrays(&arrays);
	arrays.str = str;
	init_arrays(&arrays, str, 0);
	return (arrays);
}

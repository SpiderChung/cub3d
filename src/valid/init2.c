/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:28:43 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:28:43 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	init_colors2(t_arrays *ar, char *temp)
{
	if (temp[0] == 'F')
		ar->colors[0] = ft_strdup(temp);
	else if (temp[0] == 'C')
		ar->colors[1] = ft_strdup(temp);
	else
		error("NON_VALID_COLORS");
	ar->flag_colors += 1;
}

void	init_colors(t_arrays *ar, char *str, int *i)
{
	char		temp[1000];
	int			k;

	while (str[*i])
	{
		k = 0;
		while (str[*i] != '\n')
			temp[k++] = str[(*i)++];
		temp[k] = '\0';
		if (k > 1)
			init_colors2(ar, temp);
		else if (k == 1)
			error("NON_VALID_COLORS2");
		(*i)++;
		if (ar->flag_colors == 2)
			break ;
	}
	(*i)--;
}

void	init_textures2(t_arrays *arrays, char *temp)
{
	if (temp[0] == 'N' && temp[1] == 'O')
		arrays->textures[0] = ft_strdup(temp);
	else if (temp[0] == 'S' && temp[1] == 'O')
		arrays->textures[1] = ft_strdup(temp);
	else if (temp[0] == 'W' && temp[1] == 'E')
		arrays->textures[2] = ft_strdup(temp);
	else if (temp[0] == 'E' && temp[1] == 'A')
		arrays->textures[3] = ft_strdup(temp);
	else
		error("ERROR: NON_VALID_TEXTURES");
	arrays->flag_textures += 1;
}

void	init_textures(t_arrays *ar, char *str, int *i)
{
	char		temp[1000];
	int			k;

	while (str[*i])
	{
		k = 0;
		while (str[*i] != '\n')
			temp[k++] = str[(*i)++];
		temp[k] = '\0';
		if (k > 1)
			init_textures2(ar, temp);
		else if (k == 1)
			error("ERROR: NON_VALID_TEXTURES");
		(*i)++;
		if (ar->flag_textures == 4)
			break ;
	}
	(*i)--;
}

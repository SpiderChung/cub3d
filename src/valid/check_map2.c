/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:33:33 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:33:33 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	check_door(t_arrays *ar)
{
	if (ar->cc == DOOR_CHAR)
	{
		if (!((ar->map[ar->ii][ar->jj + 1] == '1'
				&& ar->map[ar->ii][ar->jj - 1] == '1')
			|| (ar->map[ar->ii - 1][ar->jj] == '1'
				&& ar->map[ar->ii + 1][ar->jj] == '1')))
		{
			error("ERROR: INVALID_DOOR");
		}
	}
}

void	ft_flag_set(t_arrays *ar)
{
	if (ar->jj == 1 && ar->map[ar->ii][ar->jj - 1] == '1')
		ar->flag_in = (ar->flag_in + 1) % 2;
	if (ar->cc == '1' && ar->map[ar->ii][ar->jj - 1] == ' ')
		ar->flag_in = (ar->flag_in + 1) % 2;
	if (ar->cc == '1' && ar->map[ar->ii][ar->jj + 1] == ' ')
		ar->flag_in = (ar->flag_in + 1) % 2;
	if (char_in_str(ar->cc, HERO_CHAR, 0))
	{
		if (ar->flag_in == 0 || ar->flag_hero == 1)
		{
			error("ERROR: INVALID_HEROES");
		}
		else
		{
			ar->flag_hero = 1;
			ar->hpx = ar->jj;
			ar->hpy = ar->ii;
			ar->direction = ar->cc;
		}
	}
}

int	ft_leacks_corner(t_arrays *ar)
{
	char	arch[9];

	if (!char_in_str(ar->cc, IN_CHAR, 0))
		return (0);
	arch[8] = '\0';
	arch[0] = ar->map[ar->ii - 1][ar->jj - 1];
	arch[1] = ar->map[ar->ii - 1][ar->jj];
	arch[2] = ar->map[ar->ii - 1][ar->jj + 1];
	arch[3] = ar->map[ar->ii][ar->jj + 1];
	arch[4] = ar->map[ar->ii + 1][ar->jj + 1];
	arch[5] = ar->map[ar->ii + 1][ar->jj];
	arch[6] = ar->map[ar->ii + 1][ar->jj - 1];
	arch[7] = ar->map[ar->ii][ar->jj - 1];
	return (char_in_str(' ', arch, 0));
}

void	check_map_in(t_arrays *ar)
{
	ar->ii = 0;
	while (++(ar->ii) < ar->map_height - 1)
	{
		ar->jj = 0;
		ar->flag_in = 0;
		while (++(ar->jj) < ar->map_width - 1)
		{
			ar->cc = ar->map[ar->ii][ar->jj];
			ft_flag_set(ar);
			check_door(ar);
			if (!char_in_str(ar->cc, MAP_CHAR, 0))
				error("ERROR: INVALID_MAP_CHAR");
			if (ft_leacks_corner(ar))
			{
				ft_putendl_fd(ar->map[ar->ii], 1);
				error("ERROR: INVALID_MAP_LEACS");
			}
		}
	}
	if (ar->flag_hero == 0)
		error("ERROR: HERO_IS_ABSENT");
}

void	check_border(t_arrays *ar)
{
	ar->ii = -1;
	ar->jj = ar->map_height - 1;
	while (++(ar->ii) < ar->map_width)
	{
		if (!(char_in_str(ar->map[0][ar->ii], BORDER_CHAR, 0)))
			error("INVALID_MAP_BORDER_LINE1");
		if (!(char_in_str(ar->map[ar->jj][ar->ii], BORDER_CHAR, 0)))
			error("INVALID_MAP_BORDER_LINE2");
	}
	ar->ii = -1;
	ar->jj = ar->map_width - 1;
	while (++(ar->ii) < ar->map_height)
	{
		if (!(char_in_str(ar->map[ar->ii][0], BORDER_CHAR, 0)) ||
		!(char_in_str(ar->map[ar->ii][ar->jj], BORDER_CHAR, 0)))
			error("INVALID_MAP_BORDER_COLUMN");
	}
}

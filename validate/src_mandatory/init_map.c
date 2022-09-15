/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:24:57 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 14:24:57 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	init_map2(t_arrays *ar, char *str, char *temp, int *i)
{
	if (ar->kk > 0 && ar->empty_string == 1)
		error("ERROR: EMPTY_STRING_IN_MAP");
	else if (ar->kk > 0)
	{
		if (temp[0] == ' ' || temp[0] == '1')
		{
			ar->map[ar->jj] = ft_strdup(temp);
			ar->jj += 1;
		}
		else
			error("NON_VALID_MAP_ELEMENTS");
		if (str[*i] == '\0')
			ar->map[ar->jj] = NULL;
	}
	else if (ar->kk == 0)
	{
		ar->empty_string = 1;
		ar->map[ar->jj] = NULL;
	}
}

void	init_map(t_arrays *ar, char *str, int *i)
{
	char		*temp;
	int			t;

	ar->jj = 0;
	temp = (char *)malloc(10000);
	t = ft_count_str(&str[*i]) + 3;
	ar->map = (char **)malloc(sizeof(char *) * t);
	while (++(ar->jj) < t)
		ar->map[ar->jj] = NULL;
	ar->jj = 0;
	while (str[*i])
	{
		ar->kk = 0;
		while (str[*i] != '\n' && str[*i] != '\0')
			temp[(ar->kk)++] = str[(*i)++];
		temp[ar->kk] = '\0';
		init_map2(ar, str, temp, i);
		if (str[*i])
		(*i)++;
	}
}

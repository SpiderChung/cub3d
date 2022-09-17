/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:37:21 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:37:21 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_num(char *tstr, int k, int *i)
{
	int		res;
	char	num[256];

	while (tstr[*i] && tstr[*i] != ',')
	{
		if (ft_isdigit(tstr[*i]))
			num[k] = tstr[*i];
		else
			error("ERROR: INCORRECT_COLORS2");
		(*i)++;
		k++;
	}
	num[k] = '\0';
	if (k == 0)
		error("ERROR: INCORRECT_COLORS3");
	res = ft_atoi((const char *)num);
	if (res < 0 || res > 255)
		error("ERROR: INCORRECT_COLORS4");
	return (res);
}

char	*temp_prepare(t_arrays *ar, int l, int i)
{
	char	*tstr;

	tstr = (char *)malloc(ft_strlen(ar->colors[l]));
	i = 0;
	while (ar->colors[l][++i])
		tstr[i - 1] = ar->colors[l][i];
	tstr[i - 1] = '\0';
	ft_str_trim(&tstr);
	return (tstr);
}

void	check_c_fornull(t_arrays *ar)
{
	ar->ii = -1;
	while (++(ar->ii) < 2)
	{
		if (ar->colors[ar->ii] == NULL)
			error("ERROR: INCORRECT_COLORS1");
	}
}

void	check_colors(t_arrays *ar)
{
	char	*tstr;
	int		i;
	int		j;
	int		l;

	l = -1;
	while (++l < 2)
	{
		tstr = temp_prepare(ar, l, 0);
		i = 0;
		j = -1;
		while (++j < 3)
		{
			if (l == 0)
				ar->f[j] = ft_num(tstr, 0, &i);
			else
				ar->c[j] = ft_num(tstr, 0, &i);
			if (tstr[i] && j < 2)
				i++;
			if (tstr[i] && j == 2)
				error("ERROR: INCORRECT_COLORS5");
		}
		free(tstr);
	}
}

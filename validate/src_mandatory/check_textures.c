/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:38:26 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 09:38:26 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	check_t_fornull(t_arrays *ar)
{
	ar->ii = -1;
	while (++(ar->ii) < 4)
	{
		if (ar->textures[ar->ii] == NULL)
			error("ERROR: INCORRECT_TEXTURES");
	}
}

void	check_textures(t_arrays *ar)
{
	char	*temp;

	check_t_fornull(ar);
	ar->jj = -1;
	while (++(ar->jj) < 4)
	{
		temp = (char *)malloc(ft_strlen(ar->textures[ar->jj]) + 1);
		ar->ii = 1;
		while (ar->textures[ar->jj][++(ar->ii)])
			temp[ar->ii - 2] = ar->textures[ar->jj][ar->ii];
		temp[ar->ii - 2] = '\0';
		ft_str_trim(&temp);
		ar->kk = open(temp, O_RDONLY);
		if (ar->kk < 0)
			error("ERROR: INCORRECT_TEXTURE_PATH");
		close(ar->kk);
		free(ar->textures[ar->jj]);
		ar->textures[ar->jj] = ft_strdup(temp);
	}
	free(temp);
}

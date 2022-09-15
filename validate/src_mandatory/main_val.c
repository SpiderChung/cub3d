/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:43:37 by kthucydi          #+#    #+#             */
/*   Updated: 2022/09/14 08:43:37 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	main(int argc, char **argv)
{
	t_validate	*val;

	val = validate(argv, argc);
	validate_print(val, -1);
	return (0);
}

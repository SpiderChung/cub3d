/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <kthucydi@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:45:45 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/15 14:00:53 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

static int	ft_minus(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	unsigned long	border;
	size_t			i;
	int				sign;

	result = 0;
	border = (unsigned long)(9223372036854775807 / 10);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_minus(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
			&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (str[i] - '0') > 8))
			&& sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kthucydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:04:47 by kthucydi          #+#    #+#             */
/*   Updated: 2021/10/15 15:29:36 by kthucydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static int	minusnull(int nb, int fd)
{	
	int	l;

	l = nb;
	if (nb == 0)
	{
		ft_putchar('0', fd);
	}	
	if (nb == -2147483648)
	{	
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		l = 147483648;
	}	
	if (l < 0)
	{
		ft_putchar('-', fd);
		l = l * -1;
	}
	return (l);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	t[20];
	int	k;

	k = 0;
	nb = minusnull(nb, fd);
	while (nb > 0)
	{
		t[k] = nb % 10 + '0';
		nb = nb / 10;
		++k;
	}
	while (--k >= 0)
		write(fd, &t[k], 1);
}

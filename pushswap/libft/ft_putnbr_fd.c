/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:23:22 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/07 11:23:52 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_nb(int nb, int fd)
{
	if (nb > 9)
	{
		print_nb(nb / 10, fd);
		print_nb(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + 48, fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	print_nb(nb, fd);
}

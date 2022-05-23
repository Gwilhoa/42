/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:23:22 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/13 10:43:05 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_nb(int nb)
{
	if (nb > 9)
	{
		print_nb(nb / 10);
		print_nb(nb % 10);
	}
	else
	{
		putchar(nb + 48);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		putchar('-');
		nb = nb * -1;
	}
	print_nb(nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:09:03 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/08 14:11:55 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = putnbr(nb / 10);
		i = i + putnbr(nb % 10);
	}
	else
	{
		i = i + ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	size;

	size = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		size = size + ft_putchar('-');
		nbr = -nbr;
	}
	return (size + putnbr(nbr));
}

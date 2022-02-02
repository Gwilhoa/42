/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:38:37 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 13:39:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	number_print( int a, int b, int c)
{
	a = a + 48;
	b = b + 48;
	c = c + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != 55 || b != 56 || c != 57)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{	
	char	a;
	char	b;
	char	c;

	a = -1;
	while (a < 7)
	{
		a++;
		b = a;
		while (b < 8)
		{
			b++;
			c = b;
			while (c < 9)
			{
				c++;
				number_print(a, b, c);
			}
		}
	}
}

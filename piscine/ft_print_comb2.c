/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:35:27 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 13:39:45 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar( char c)
{
	write(1, &c, 1);
}

void	number_print( int n1, int n2)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = n1 / 10 + 48;
	b = n1 % 10 + 48;
	c = n2 / 10 + 48;
	d = n2 % 10 + 48;
	putchar(a);
	putchar(b);
	putchar(' ');
	putchar(c);
	putchar(d);
	if (n1 != 98)
	{
		putchar(',');
		putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (a < 98)
	{
		a++;
		b = a;
		while (b < 99)
		{
			b++;
			number_print(a, b);
		}
	}
}

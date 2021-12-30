/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:42:18 by guilheimcha       #+#    #+#             */
/*   Updated: 2021/12/22 12:15:31 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == 0)
		return ft_putstr("(null)");
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = putnbr(nb/10);
		i = i + putnbr(nb%10);
	}
	else
	{
		i = i + ft_putchar(nb + 48);
	}
	return (i);
}

int ft_putunsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = ft_putunsigned(nb/10);
		i = i + ft_putunsigned(nb%10);
	}
	else
	{
		i = i + ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int size;

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

int ft_puthexnbr(unsigned int nbr)
{
	char tab[16] = "0123456789abcdef";
	int	i;

	i = 0;
	if (nbr > 15)
	{
		i = ft_puthexnbr(nbr/16);
		i = i + ft_puthexnbr(nbr%16);
	}
	else
	{
		i = i + ft_putchar(tab[nbr]);
	}
	return (i);
}

int ft_putpointer(unsigned long long nbr)
{
	char tab[16] = "0123456789abcdef";
	int	i;

	i = 0;
	if (nbr > (unsigned int)15)
	{
		i = ft_putpointer(nbr/(unsigned int)16);
		i = i + ft_putpointer(nbr%(unsigned int)16);
	}
	else
	{
		i = i + ft_putchar(tab[nbr]);
	}
	return (i);
}

int ft_puthexnbr2(unsigned int nbr)
{
	char tab[16] = "0123456789ABCDEF";
	int	i;

	i = 0;
	if (nbr > 15)
	{
		i = ft_puthexnbr2(nbr/16);
		i = i + ft_puthexnbr2(nbr%16);
	}
	else
	{
		i = i + ft_putchar(tab[nbr]);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		size;
	char	c;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			c = str[i];
			if (c == 'c')
				size = size + ft_putchar(va_arg(args, int));
			else if (c == 's')
				size = size + ft_putstr(va_arg(args, char *));
			else if (c == 'i' || c == 'd')
				size = size + ft_putnbr(va_arg(args, int));
			else if (c == 'x')
				size = size + ft_puthexnbr(va_arg(args, unsigned int));
			else if (c == 'X')
				size = size + ft_puthexnbr2(va_arg(args, unsigned int));
			else if (c == 'p')
			{
				size = size + ft_putstr("0x");
				size = size + ft_putpointer(va_arg(args, unsigned long long));
			}
			else if (c == '%')
				size = size + ft_putchar('%');
			else if (c == 'u')
				size = size + ft_putunsigned(va_arg(args, unsigned int));
		}
		else
			size = size + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}

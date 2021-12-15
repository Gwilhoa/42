/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:48:19 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/21 16:33:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_func_test(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'd' || c == 'i')
		size += ft_func_i(va_arg(args, int));
	else if (c == 'X')
		size += ft_func_x2(va_arg(args, int));
	else if (c == 's')
		size += ft_func_s(va_arg(args, char *));
	else if (c == 'x')
		size += ft_func_x((int) va_arg(args, int));
	else if (c == 'c')
		size += ft_func_c(va_arg(args, int));
	else if (c == 'p')
		size += ft_func_p(va_arg(args, unsigned long long));
	else if (c == 'u')
		size += ft_func_u(va_arg(args, unsigned int));
	return (size);
}

int	ft_printf( const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	va_start(args, format);
	while (i < ft_strlen(format))
	{
		c = format[i];
		if (c != '%')
			size += ft_func_c(c);
		else
		{
			c = format[++i];
			if (c != '%')
				size += ft_func_test(c, args);
			else
				size += ft_func_c('%');
		}
		i++;
	}
	va_end(args);
	return (size);
}

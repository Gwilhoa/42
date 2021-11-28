/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:35:18 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:37 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_func_p(unsigned long c)
{
<<<<<<< HEAD
	int		i;
	char	*str;

	i = ft_func_s("0x");
	str = ft_changebase_p(c, "0123456789abcdef");
	i = ft_func_s(str) + i;
	free(str);
=======
	int	i;

	i = 0;
	if (c == 0)
		return (ft_func_s(str));
	i += ft_func_s("0x");
	i += ft_func_x(c);
>>>>>>> parent of cf1e795 (fin printf)
	return (i);
}

int	ft_func_x2(int c)
{
	char	*str;
	int		i;

	str = ft_changebase(c, "0123456789ABCDEF");
	i = ft_func_s(str);
	free(str);
	return (i);
}

int	ft_func_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_func_i(int c)
{
	ft_putnbr_fd(c, 1);
	return (sizedigit(c));
}

int	ft_func_s(char *str)
{
	if (!str)
		return (ft_func_s("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

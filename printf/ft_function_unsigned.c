/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:18:28 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:24 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void	print_nb2(unsigned int nb, int fd)
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

int	ft_func_u(unsigned int c)
{
	print_nb2(c, 1);
	return (sizedigit(c));
}
<<<<<<< HEAD

int	sizedigithex(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_changebase_p(unsigned long long nbr, char *base)
{
	int			i;
	char		*ret;

	ret = malloc((sizedigithex(nbr) + 1) * sizeof(char));
	i = 0;
	if (ft_strlen(base) == 0)
		return (0);
	if (check_base(base) == 1)
	{
		while (nbr >= (unsigned int)ft_strlen(base))
		{
			ret[i++] = base[nbr % ft_strlen(base)];
			nbr = nbr / ft_strlen(base);
		}
		ret[i] = base[nbr % ft_strlen(base)];
		i++;
		ret[i] = 0;
		ft_rev_tab(ret, ft_strlen(ret));
		return (ret);
	}
	return (0);
}
=======
>>>>>>> parent of cf1e795 (fin printf)

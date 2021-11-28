/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:24:57 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/27 18:13:04 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_func_x(long long c)
{
	char	*str;
	int		i;

	str = ft_changebase(c, "0123456789abcdef");
	i = ft_func_s(str);
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		if (ft_strlen(base) < 2)
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_rev_tab(char *tab, int size)
{
	char	temp;
	int		i;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int	sizedigit(long long n)
{
	long long	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		ret++;
	}
	ret++;
	return (ret);
}

char	*ft_changebase(unsigned int nbr, char *base)
{
	int			i;
	char		*ret;

	ret = malloc(sizedigit(nbr) + 1 * sizeof(long));
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
		ft_rev_tab(ret, ft_strlen(ret));
		return (ret);
	}
	return (0);
}

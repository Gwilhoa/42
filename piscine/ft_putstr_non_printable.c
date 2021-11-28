/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:57:33 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/13 09:16:09 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	hexa(char i)
{
	char	*l;

	l = "0123456789abcdef";
	write(1, &l[i / 16], 1);
	write(1, &l[i % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= 32 && str[i] < 127)))
		{
			write(1, "\\", 1);
			hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
	}
}

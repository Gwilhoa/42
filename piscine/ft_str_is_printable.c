/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:57:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 07:32:27 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] > 31 && str[i] < 127)))
		{
			return (0);
		}
	}
	return (1);
}

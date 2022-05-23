/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:35:49 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 07:23:00 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s;

	s = 0;
	i = 0;
	while (i < size)
	{
		if (src[i])
		{
			dest[i] = src[i];
			s++;
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (s + 1);
}

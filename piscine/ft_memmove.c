/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:47:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:37:05 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	i = 0;
	s = (char *) src;
	d = (char *) dest;
	while (i < n || s)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

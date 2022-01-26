/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:35:16 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:38:00 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*v;

	i = 0;
	v = (char *) s;
	while (i < n)
	{
		v[i] = c;
		i++;
	}
	return (s);
}

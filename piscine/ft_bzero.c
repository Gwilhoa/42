/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:36:51 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:31:48 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*v;

	i = 0;
	v = (char *)s;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
	return (s);
}

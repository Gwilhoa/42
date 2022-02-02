/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:36:51 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/31 22:31:50 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*v;

	i = 0;
	v = (char *) s;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
	return (s);
}

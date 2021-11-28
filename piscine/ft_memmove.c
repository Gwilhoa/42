/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:47:38 by gchatain          #+#    #+#             */
/*   Updated: 2021/10/03 20:47:38 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	char*	d;
	char*	s;

	i = 0;
	s = (char*)src;
	d = (char*)dest;

	while(i<n || s){
		d[i] = s[i];
		i++;
	}

	return d;
}


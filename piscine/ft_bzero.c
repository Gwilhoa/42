/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:36:51 by gchatain          #+#    #+#             */
/*   Updated: 2021/09/16 22:36:51 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_bzero(void *s, size_t n){
	unsigned int i;

	i = 0;
	char* v = (char*)s;
	while (i<n){
		v[i] = 0;
		i++;
	}
	return (s);
}

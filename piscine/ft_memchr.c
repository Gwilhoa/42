/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:38:31 by gchatain          #+#    #+#             */
/*   Updated: 2021/10/04 10:38:31 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
 void *memchr(const void *s, int c, size_t n){
	
	char *str = (char *)s;
	unsigned int i;

	i = 0;

	while (str++ && str[0] && i<n)
	{
		if (str[0] == c)
			return str;
		i++;
	}
	return 0;
}

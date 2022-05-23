/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:38:31 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:35:14 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	while (str++ && str[0] && i < n)
	{
		if (str[0] == c)
			return (str);
		i++;
	}
	return (0);
}

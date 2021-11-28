/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:30:50 by gchatain          #+#    #+#             */
/*   Updated: 2021/10/04 09:30:50 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strchr(const char *s, int c)
{
	char *str =(char*) s;
	int i;

	i = 0;

	while (str++ && str[0])
	{
		if (str[0] == c)
			return str;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:58:33 by gchatain          #+#    #+#             */
/*   Updated: 2021/10/04 09:58:33 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	char *str = (char*)s;
	int i;
	int p;

	i = 0;
	p = -1;

	while (s[i])
	{
		if (s[i] == c)
			p = i;
		i++;
	}
	if (p == -1)
		return 0;
	return str+p;
}


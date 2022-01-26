/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:56:27 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:36:04 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	s1 = (char *) str1;
	s2 = (char *) str2;
	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

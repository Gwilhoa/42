/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:02:53 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 07:22:40 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	unsigned int	i;
	int				j;
	char			*str1;

	str1 = (char *)big;
	i = 0;
	j = 0;
	while (str1[i] && i < len)
	{
		if (str1[i] == str1[j])
			j++;
		else
		{
			if (!little[j])
				return (str1 + i - j);
			i = i - j;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:57:33 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/13 09:48:06 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
char	*ft_strlowcase(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 64 && str[i] < 91)
		{
			str[i] = str[i] + 32;
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		n;

	i = 0;
	*str = *ft_strlowcase(str);
	while (str[i])
	{
		n = i;
		if ((!((str[i] >= '0' && str[i] <= '9')
					|| (str[i] >= 'a' && str[i] <= 'z')
					|| (str[i] >= 'A' && str[i] <= 'Z'))) || (i == 0))
		{
			if (i != 0)
			{
				n++;
			}
			if (str[n] > 96 && str[n] < 123)
			{
				str[n] = str[n] - 32;
			}
		}
		i++;
	}
	return (str);
}

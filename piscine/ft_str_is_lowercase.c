/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lowercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:57:33 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/11 17:34:18 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] > 96 && str[i] < 123)))
		{
			return (0);
		}
	}
	return (1);
}

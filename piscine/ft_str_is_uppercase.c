/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:57:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 07:21:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)

{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')))
		{
			return (0);
		}
	}
	return (1);
}

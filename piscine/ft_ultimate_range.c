/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:07:34 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/29 15:13:23 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	range[0] = malloc((max - min) * sizeof(int));
	if (!range[0])
		return (-1);
	i = 0;
	while (i < max - min)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}

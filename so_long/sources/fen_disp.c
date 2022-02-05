/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fen_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:11 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 06:43:42 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh(void *link, void *fen, t_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			setfloor(link, fen, i, j);
			j++;
		}
		i++;
	}
}

void	setfloor(void *link, void *fen, int i, int j)
{
	int		*s;
	void	*img;

	*s = 32;
	img = mlx_xpm_file_to_image(link, "sprites/floor.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

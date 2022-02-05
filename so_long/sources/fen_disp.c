/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fen_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:11 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 07:19:07 by gchatain         ###   ########lyon.fr   */
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
			if (game->matrice[i][j] == '0')
				setfloor(link, fen, j, i);
			if (game->matrice[i][j] == '1')
				setwall(link, fen, j, i);
			if (game->matrice[i][j] == 'P')
				setperso(link, fen, j, i);
			if (game->matrice[i][j] == 'C')
				setitem(link, fen, j, i);
			if (game->matrice[i][j] == 'E')
				setexit(link, fen, j, i);
			j++;
		}
		i++;
	}
}

void	setfloor(void *link, void *fen, int i, int j)
{
	int		*s;
	int		n;
	void	*img;

	s = &n;
	img = mlx_xpm_file_to_image(link, "sprites/floor.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

void	setwall(void *link, void *fen, int i, int j)
{
	int		*s;
	int		n;
	void	*img;

	s = &n;
	img = mlx_xpm_file_to_image(link, "sprites/wall.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

void	setperso(void *link, void *fen, int i, int j)
{
	int		*s;
	int		n;
	void	*img;

	s = &n;
	img = mlx_xpm_file_to_image(link, "sprites/perso.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

void	setitem(void *link, void *fen, int i, int j)
{
	int		*s;
	int		n;
	void	*img;

	s = &n;
	img = mlx_xpm_file_to_image(link, "sprites/items.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

void	setexit(void *link, void *fen, int i, int j)
{
	int		*s;
	int		n;
	void	*img;

	s = &n;
	img = mlx_xpm_file_to_image(link, "sprites/exit.xpm", s, s);
	mlx_put_image_to_window(link, fen, img, i * 32, j * 32);
}

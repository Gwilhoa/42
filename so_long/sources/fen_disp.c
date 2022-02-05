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

void	refresh(t_long *game)
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
				mlx_put_image_to_window(game->link, game->fen, game->floor,
					i * 32, j * 32);
			if (game->matrice[i][j] == '1')
				mlx_put_image_to_window(game->link, game->fen, game->wall,
					i * 32, j * 32);
			if (game->matrice[i][j] == 'P')
				mlx_put_image_to_window(game->link, game->fen, game->perso,
					i * 32, j * 32);
			if (game->matrice[i][j] == 'C')
				mlx_put_image_to_window(game->link, game->fen, game->items,
					i * 32, j * 32);
			if (game->matrice[i][j] == 'E')
				mlx_put_image_to_window(game->link, game->fen, game->exit,
					i * 32, j * 32);
			j++;
		}
		i++;
	}
}

void	init_image(t_long **game)
{
	t_long	*temp;
	int		*s;
	int		n;

	s = &n;
	temp = *game;
	temp->floor = mlx_xpm_file_to_image(temp->link, "sprites/floor.xpm", s, s);
	temp->wall = mlx_xpm_file_to_image(temp->link, "sprites/wall.xpm", s, s);
	temp->items = mlx_xpm_file_to_image(temp->link, "sprites/items.xpm", s, s);
	temp->exit = mlx_xpm_file_to_image(temp->link, "sprites/exit.xpm", s, s);
	temp->perso = mlx_xpm_file_to_image(temp->link, "sprites/perso.xpm", s, s);
	*game = temp;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fen_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:11 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/16 13:10:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh(t_long *game)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < game->width)
	{
		x = -1;
		while (x++ < game->height)
		{
			if (game->matrice[y][x] == '1')
				put_image(game, game->wall, x, y);
			else if (game->matrice[y][x] == 'C')
				put_image(game, game->items, x, y);
			else if (game->matrice[y][x] == 'E')
				put_image(game, game->exit, x, y);
			else
				put_image(game, game->floor, x, y);
		}
	}
	put_image(game, game->perso, game->p_x, game->p_y);
	put_enemy(game);
}

void	put_enemy(t_long *game)
{
	int	i;

	i = 0;
	if (game->enemies == NULL)
		return ;
	while (&game->enemies[i])
	{
		put_image(game, game->enemy, game->enemies[i].x, game->enemies[i].y);
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
	temp->enemy = mlx_xpm_file_to_image(temp->link, "sprites/enemy.xpm", s, s);
	*game = temp;
}

void	put_image(t_long *game, void *image, int x, int y)
{
	int	*s;
	int	n;

	s = &n;
	mlx_put_image_to_window(game->link, game->fen, image, x * 32, y * 32);
}

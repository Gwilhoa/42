/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/16 13:08:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_long	*game;

	game = malloc(1 * sizeof(t_long));
	game->enemies = NULL;
	if (init(argc, argv, &game) == 0)
	{
		exit(EXIT_FAILURE);
		return (0);
	}
	game->link = mlx_init();
	game->fen = mlx_new_window(game->link, game->height * 32,
			(1 + game->width) * 32, "so_long");
	init_image(&game);
	refresh(game);
	mlx_key_hook(game->fen, move, &game);
	mlx_hook(game->fen, 17, 1L << 2, ft_close, game);
	mlx_loop(game->link);
	return (0);
}

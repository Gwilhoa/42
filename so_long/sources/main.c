/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/09 11:43:54 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_long	*game;

	game = malloc(1 * sizeof(t_long));
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

int	init(int argc, char const *argv[], t_long **game)
{
	int		fd;
	STRING	str;
	t_long	*temp;

	temp = *game;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nargs format", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str || ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error\nfile error", 1);
		return (0);
	}
	temp->height = ft_strlen(str) - 1;
	if (complete_matrice(fd, &temp, str) == 0 || verif_matrice(&temp) == 0)
	{
		ft_putstr_fd("Error\nmap format or arguments map", 1);
		return (0);
	}
	temp->count = 0;
	return (1);
}

int	complete_matrice(int fd, t_long **game, STRING str)
{
	t_long	*temp;
	int		i;

	i = 0;
	temp = *game;
	temp->matrice = malloc((1 + temp->height) * sizeof(STRING *));
	while (ft_strlen(str) - 1 == temp->height)
	{
		temp->matrice[i] = str;
		str = get_next_line(fd);
		i++;
	}
	temp->matrice[i] = str;
	str = get_next_line(fd);
	if (str != NULL)
		return (0);
	temp->matrice[i + 1] = NULL;
	temp->width = i;
	*game = temp;
	return (1);
}

int	verif_matrice(t_long **game)
{
	int		x;
	int		y;
	t_long	*temp;

	x = -1;
	temp = *game;
	temp->p_x = -1;
	temp->count_items = 0;
	while (x++ < temp->width)
	{
		y = -1;
		while (y++ < temp->height - 1)
		{
			if ((x == 0 || y == 0 || x == temp->width
					|| y == temp->height - 1) && temp->matrice[x][y] != '1')
				return (0);
			if (temp->matrice[x][y] == 'P')
				if (init_perso(&temp, x, y) == 0)
					return (0);
			if (temp->matrice[x][y] == 'C')
				temp->count_items++;
		}
	}
	return (1);
}

int	init_perso(t_long **game, int x, int y)
{
	t_long	*temp;

	temp = *game;
	if (temp->p_x != -1)
		return (0);
	temp->p_x = y;
	temp->p_y = x;
	return (1);
}

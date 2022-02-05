/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:06:03 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 12:46:23 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	void	*link;
	void	*fen;
	void	*func;
	t_long	*game;

	func = move();
	if (init(argc, argv, &game) == 0)
	{
		ft_putstr_fd("Error\n map format", 1);
		exit(EXIT_FAILURE);
		return (0);
	}
	link = mlx_init();
	fen = mlx_new_window(link, game->height * 32, game->width * 32, "so_long");
	refresh(link, fen, game);
	mlx_key_hook(fen, move, &game);
	mlx_loop(link);
	return (0);
}

int	init(int argc, char const *argv[], t_long **game)
{
	int		fd;
	STRING	str;
	t_long	*temp;

	temp = malloc(1 * sizeof(t_long));
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	temp->height = ft_strlen(str) - 1;
	if (complete_matrice(fd, &temp, str) == 0)
	{
		*game = temp;
		return (0);
	}
	*game = temp;
	return (1);
}

int	complete_matrice(int fd, t_long **game, STRING str)
{
	t_long	*temp;
	int		i;

	i = 0;
	temp = *game;
	temp->matrice = malloc((1 + temp->height) * sizeof(STRING *));
	while (str)
	{
		temp->matrice[i] = str;
		str = get_next_line(fd);
		i++;
	}
	temp->matrice[i] = NULL;
	temp->width = i - 1;
	*game = temp;
	if (temp->height < temp->width)
		return (0);
	return (1);
}

int *move()
{
	int	i;
	int	*s;

	i = 5;
	s = &i;
	ft_putchar_fd('t',1);
	return (s);
}

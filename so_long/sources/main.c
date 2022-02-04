/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/04 11:43:13 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	void	*link;
	void	*fen;
	int		fd;
	t_long	*game;

	if (init(argc, argv, &game) == 0)
	{
		ft_putstr_fd("Error\n map format", 1);
		exit(EXIT_FAILURE);
		return (0);
	}
	link = mlx_init();
	fen = mlx_new_window(link, game->height, game->width, "so_long");
	mlx_loop(link);
	return (0);
}

int	init(int argc, char const *argv[], t_long **game)
{
	int		fd;
	int		*ret;
	STRING	str;
	t_long	*temp;

	temp = malloc(1 * sizeof(t_long));
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	temp->height = ft_strlen(str);
	if (complete_matrice(fd, &temp, str) == 0)
	{
		game = &temp;
		return (0);
	}
	game = &temp;
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
	temp->width = i;
	game = &temp;
	if (temp->height < temp->width)
		return (0);
	return (1);
}

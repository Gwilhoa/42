/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/03 22:22:00 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*link;
	void	*fen;
	void	*wall;
	int		size;
	int		fd;

	size = 16;
	fd = open("test.ber", O_RDONLY);
	link = mlx_init();
	fen = mlx_new_window(link, 500, 500, "test");
	wall = mlx_xpm_file_to_image(link, "sprites/wall.xpm", &size, &size);
	mlx_put_image_to_window(link, fen, wall, 0, 0);
	mlx_loop(link);
	return (0);
}

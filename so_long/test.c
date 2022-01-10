/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/10 14:28:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(int argc, char const *argv[])
{
	void	*link;
	void	*fen;

	link = mlx_init();
	fen = mlx_new_window(link, 500, 500, "so_long");
	mlx_pixel_put(link, fen, 250, 250,0xFFFFFF);
	mlx_loop(fen);
	return 0;
}

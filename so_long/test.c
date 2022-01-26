/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 14:40:54 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int	main(void)
{
	void	*link;
	void	*fen;

	link = mlx_init();
	fen = mlx_new_window(link, 500, 500, "test");
	mlx_loop(link);
	return (0);
}

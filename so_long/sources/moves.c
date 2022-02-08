/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:11:10 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/08 11:24:30 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_long *temp)
{
	mlx_destroy_window(temp->link, temp->fen);
	exit(EXIT_SUCCESS);
}

int	move(int keycode, t_long **game)
{
	t_long	*temp;

	temp = *game;
	if (keycode == ESCAPE_BIND)
		return (ft_close(temp));
	put_image(temp, temp->floor, temp->p_x, temp->p_y);
	if (keycode == UP_BIND)
		move_matrice(game, temp->p_x, temp->p_y - 1);
	if (keycode == DOWN_BIND)
		move_matrice(game, temp->p_x, temp->p_y + 1);
	if (keycode == LEFT_BIND)
		move_matrice(game, temp->p_x - 1, temp->p_y);
	if (keycode == RIGHT_BIND)
		move_matrice(game, temp->p_x + 1, temp->p_y);
	put_image(temp, temp->perso, temp->p_x, temp->p_y);
	return (1);
}

int	move_matrice(t_long **game, int x, int y)
{
	t_long	*temp;

	temp = *game;
	if (temp->matrice[y][x] == '1')
		return (0);
	if (temp->matrice[y][x] == 'E')
	{
		if (temp->count_items == 0)
			ft_close(temp);
		else
			return (0);
	}
	if (temp->matrice[y][x] == 'C')
	{
		temp->count_items--;
		temp->matrice[y][x] = '0';
	}
	temp->count++;
	ft_printf("coups : %d\n", temp->count);
	temp->p_y = y;
	temp->p_x = x;
	return (1);
}

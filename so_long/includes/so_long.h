/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:29 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/16 13:26:40 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"

# define LEFT_BIND 0
# define RIGHT_BIND 2
# define UP_BIND 13
# define DOWN_BIND 1
# define ESCAPE_BIND 53

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_long
{
	void	*link;
	void	*fen;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		count_items;
	int		count_enemy;
	int		count;
	int		e;
	t_enemy	*enemies;

	void	*enemy;
	void	*floor;
	void	*wall;
	void	*perso;
	void	*items;
	void	*exit;

	STRING	*matrice;
}	t_long;

int		init(int argc, char const *argv[], t_long **game);
int		complete_matrice(int fd, t_long **game, STRING str);
void	refresh(t_long *game);
int		move(int keycode, t_long **game);
void	init_image(t_long **game);
void	put_image(t_long *game, void *image, int x, int y);
void	put_enemy(t_long *game);
int		verif_matrice(t_long **game);
int		move_matrice(t_long **game, int x, int y);
int		ft_close(t_long *temp);
int		init_perso(t_long **game, int x, int y);

#endif

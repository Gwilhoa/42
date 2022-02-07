/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:29 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/07 10:58:50 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"

typedef struct s_long
{
	void	*link;
	void	*fen;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		count_items;

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
int		move(int keycode, t_long *game);
void	init_image(t_long **game);
void	put_image(t_long *game, void *image, int x, int y);
int		verif_matrice(t_long **game);

#endif

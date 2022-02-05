/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:29 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/05 12:43:19 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"

typedef struct s_long
{
	int		width;
	int		height;
	STRING	*matrice;
}	t_long;

int		init(int argc, char const *argv[], t_long **game);
int		complete_matrice(int fd, t_long **game, STRING str);
void	refresh(void *link, void *fen, t_long *game);
int		*move(void);

void	setfloor(void *link, void *fen, int i, int j);
void	setwall(void *link, void *fen, int i, int j);
void	setperso(void *link, void *fen, int i, int j);
void	setitem(void *link, void *fen, int i, int j);
void	setexit(void *link, void *fen, int i, int j);

#endif

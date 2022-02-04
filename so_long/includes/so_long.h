/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheimchataing <guilheimchataing@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:29 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/04 11:45:20 by guilheimcha      ###   ########lyon.fr   */
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

int	init(int argc, char const *argv[], t_long **game);
int	complete_matrice(int fd, t_long **game, STRING str);

#endif

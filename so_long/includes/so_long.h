/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:29 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/04 11:27:08 by gwilhoa          ###   ########.fr       */
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
	STRING	**matrice;
}	t_long;

#endif

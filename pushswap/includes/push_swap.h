/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/31 19:12:11 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

void	swap(t_list **lst, char c);
void	push(t_list **from, t_list **to, char c);
void	rotate(t_list **lst, char c);
void	reverse_rotate(t_list **lst, char c);

int		lst_lowest_index(t_list *lst);
int		lst_highest_index(t_list *lst);
int		lst_highest(t_list *lst);
void	lst_scroll(t_list **lst, int size);

#endif

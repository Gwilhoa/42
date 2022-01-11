/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 21:45:49 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	reverse_rotate(t_list **lst);
void	rotate(t_list **lst);
void	push(t_list **from, t_list **to);
void	swap(t_list **lst);
/////////////////
int		lst_get_index(t_list *lst, int index);
int		lst_get_top(t_list *lst);
int		lst_get_bottom(t_list *lst);
int		lst_clear_top(t_list **lst);
int		lst_clear_bottom(t_list **lst);
void	lst_add_front(t_list **lst, int nb);
void	lst_add_back(t_list **lst, int nb);
void	lst_display(t_list *stack);

#endif

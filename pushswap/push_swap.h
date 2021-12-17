/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/17 10:53:52 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

int			pop(t_list **this);
void		push(t_list **this, int i);
void		display(t_list *stack1, t_list *stack2);
void		swap(t_list **this);
void		reverse_rotate(t_list **this);
void		rotate(t_list **this);
void		trade(t_list **from, t_list **to);

#endif

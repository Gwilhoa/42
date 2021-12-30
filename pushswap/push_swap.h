/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheimchataing <guilheimchataing@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/21 20:31:46 by guilheimcha      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

int			init(t_list **stack, const char **args);
int			pop(t_list **this);
void		ft_push(t_list **stack1, t_list **stack2, char c);
void		push(t_list **this, int i);
void		display(t_list *stack1, t_list *stack2);
void		swap(t_list **this);
void		reverse_rotate(t_list **this);
void		rotate(t_list **this);
void		trade(t_list **from, t_list **to);
void		ft_swap(t_list **stack1, t_list **stack2, char c);

#endif

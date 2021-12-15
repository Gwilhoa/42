/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:41:46 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/15 18:42:44 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **this)
{
	int arg1;
	int arg2;

	arg1 = pop(this);
	arg2 = pop(this);
	push(this, arg2);
	push(this, arg1);
}

void	trade(t_stack **from, t_stack **to)
{
	int	elem;

	if (from == 0)
		return;
	elem = pop(from);
	push(to, elem);
}
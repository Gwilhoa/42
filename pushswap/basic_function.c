/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:39:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 21:44:45 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	int	i;
	int	j;

	if (ft_lstsize(*lst) <= 1)
		return ;
	i = lst_clear_top(lst);
	j = lst_clear_top(lst);
	lst_add_front(lst, i);
	lst_add_front(lst, j);
	return ;
}

void	push(t_list **from, t_list **to)
{
	int	i;

	i = lst_clear_top(from);
	lst_add_front(to, i);
}

void	rotate(t_list **lst)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_back(lst, lst_clear_top(lst));
}

void	reverse_rotate(t_list **lst)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_front(lst, lst_clear_bottom(lst));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:39:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/22 10:16:27 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	int	i;
	int	j;

	if (ft_lstsize(*lst) <= 1)
		return ;
	i = lst_clear_top(lst);
	j = lst_clear_top(lst);
	lst_add_front(lst, i);
	lst_add_front(lst, j);
	ft_printf("s%c\n", c);
	return ;
}

void	push(t_list **from, t_list **to, char c)
{
	int	i;

	i = lst_clear_top(from);
	lst_add_front(to, i);
	ft_printf("p%c\n", c);
}

void	rotate(t_list **lst, char c)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_back(lst, lst_clear_top(lst));
	if (c != 'c')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **lst, char c)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_front(lst, lst_clear_bottom(lst));
	ft_printf("rr%c\n", c);
}

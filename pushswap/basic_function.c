/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:39:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/22 17:33:33 by gchatain         ###   ########.fr       */
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
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	push(t_list **from, t_list **to, char c)
{
	int	i;

	i = lst_clear_top(from);
	lst_add_front(to, i);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate(t_list **lst, char c)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_back(lst, lst_clear_top(lst));
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	reverse_rotate(t_list **lst, char c)
{
	if (ft_lstsize(*lst) <= 1)
		return ;
	lst_add_front(lst, lst_clear_bottom(lst));
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:39 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/25 16:12:50 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri(t_list **stacka, t_list **stackb)
{
	int	size;

	size = ft_lstsize(*stacka);
	if (size == 2)
	{
		swap(stacka, 'a');
		return (0);
	}
	if (size == 3)
		return (tri_three(stacka));
	return (tri_main(stacka, stackb));
}

int	tri_three(t_list **stacka)
{
	if (lst_get_index(*stacka, 0) > lst_get_index(*stacka, 1)
		&& lst_get_index(*stacka, 1) < lst_get_index(*stacka, 2)
		&& lst_get_index(*stacka, 0) > lst_get_index(*stacka, 2))
		rotate(stacka, 'a');
	if (lst_get_index(*stacka, 0) > lst_get_index(*stacka, 1))
		swap(stacka, 'a');
	if (lst_get_index(*stacka, 1) > lst_get_index(*stacka, 2))
		reverse_rotate(stacka, 'a');
	if (lst_get_index(*stacka, 0) > lst_get_index(*stacka, 2))
		rotate(stacka, 'a');
	if (lst_get_index(*stacka, 0) > lst_get_index(*stacka, 1))
		swap(stacka, 'a');
	return (0);
}

int	tri_main(t_list **stacka, t_list **stackb)
{
	int	m;
	int	size;
	int	high;

	size = ft_lstsize(*stacka);
	m = (lst_lowest(*stacka) + lst_highest(*stacka)) / 1.25;
	while (size != 3)
	{
		high = lst_highest(*stacka);
		if (high < m)
			m = (lst_lowest(*stacka) + high) / 1.25;
		if (lst_get_top(*stacka) >= m)
		{
			push(stacka, stackb, 'b');
			size--;
		}
		else
			rotate(stacka, 'a');
	}
	tri_three(stacka);
	size = ft_lstsize(*stackb);
	while (size-- > 0)
		tri_bubble(stacka, stackb);
	while (lst_is_sort(*stacka) == 0)
	{
		if (lst_lowest_index(*stacka) < ft_lstsize(*stacka) / 2)
			rotate(stacka, 'a');
		else
			reverse_rotate(stacka, 'a');
	}
	return (0);
}

int	tri_bubble(t_list **stacka, t_list **stackb)
{
	if (lst_get_top(*stackb) > lst_lowest(*stacka)
		&& lst_get_top(*stackb) < lst_highest(*stacka))
	{
		while (lst_get_top(*stacka) < lst_get_top(*stackb)
			|| lst_get_top(*stackb) < lst_get_bottom(*stacka))
		{
			if (search_place(*stacka, lst_get_top(*stackb))
				< ft_lstsize(*stacka) / 2)
				rotate(stacka, 'a');
			else
				reverse_rotate(stacka, 'a');
		}
	}
	else
	{
		while (lst_lowest_index(*stacka) != 0)
		{
			if (lst_lowest_index(*stacka) < ft_lstsize(*stacka) / 2)
				rotate(stacka, 'a');
			else
				reverse_rotate(stacka, 'a');
		}
	}
	push(stackb, stacka, 'a');
	return (1);
}

int	search_place(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst_get_index(lst, i + 1) < index
		|| index < lst_get_index(lst, i))
	{
		i++;
		if (i + 1 == ft_lstsize(lst))
			return (0);
	}
	return (i + 1);
}

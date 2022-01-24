/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:39 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/22 17:37:10 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(*stacka) == 2)
	{
		swap(stacka, 'a');
		return (0);
	}
	if (ft_lstsize(*stacka) == 3)
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

	m = (lst_lowest(*stacka) + lst_highest(*stacka)) / 1.25;
	while (ft_lstsize(*stacka) != 3)
	{
		if (lst_highest(*stacka) < m)
			m = (lst_lowest(*stacka) + lst_highest(*stacka)) / 1.25;
		else if (lst_get_top(*stacka) >= m)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	tri_three(stacka);
	while (ft_lstsize(*stackb) > 0)
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

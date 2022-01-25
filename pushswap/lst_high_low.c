/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_high_low.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:14:57 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/25 14:19:52 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_lowest_index(t_list *lst)
{
	int	i;
	int	low;
	int	index;

	i = 0;
	low = INT_MAX;
	while (lst)
	{
		if (*(int *)lst->content < low)
		{
			low = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

int	lst_highest_index(t_list *lst)
{
	int	i;
	int	high;
	int	index;

	i = 0;
	high = INT_MIN;
	while (lst)
	{
		if (*(int *)lst->content > high)
		{
			high = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

int	lst_lowest(t_list *lst)
{
	int	nb;

	nb = lst_lowest_index(lst);
	return (lst_get_index(lst, nb));
}

int	lst_highest(t_list *lst)
{
	int	nb;

	nb = lst_highest_index(lst);
	return (lst_get_index(lst, nb));
}

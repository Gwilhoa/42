/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_high_low.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:14:57 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/19 14:25:33 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_lowest_index(t_list *lst)
{
	int	i;
	int	low;

	i = 1;
	low = 0;
	while (i < ft_lstsize(lst))
	{
		if (lst_get_index(lst, i) < lst_get_index(lst, low))
			low = i;
		i++;
	}
	return (low);
}

int	lst_highest_index(t_list *lst)
{
	int	i;
	int	low;

	i = 1;
	low = 0;
	while (i < ft_lstsize(lst))
	{
		if (lst_get_index(lst, i) > lst_get_index(lst, low))
			low = i;
		i++;
	}
	return (low);
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

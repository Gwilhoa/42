/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:07:52 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/31 22:50:58 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lst_get_index(t_list *lst, int index)
{
	int	i;
	int	ret;

	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	ret = lst->content;
	return (ret);
}

int	lst_get_top(t_list *lst)
{
	int	ret;

	ret = lst->content;
	return (ret);
}

int	lst_get_bottom(t_list *lst)
{
	int	ret;

	while (lst->next)
	{
		ret = lst->content;
		lst = lst->next;
	}
	ret = lst->content;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:07:52 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 19:19:38 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	lst_get_index(t_list *lst, int index)
{
	int	i;
	int	*ret;

	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	ret = lst->content;
	return (*ret);
}

int	lst_get_top(t_list *lst)
{
	int	*ret;

	ret = lst->content;
	return (*ret);
}

int	lst_get_bottom(t_list *lst)
{
	int	*ret;

	while (lst->next)
	{
		ret = lst->content;
		lst = lst->next;
	}
	ret = lst->content;
	return (*ret);
}

void	lst_add_front(t_list **lst, int nb)
{
	int	*ret;

	ret = malloc(1 * sizeof(int));
	ret[0] = nb;
	ft_lstadd_front(lst, ft_lstnew(ret));
}

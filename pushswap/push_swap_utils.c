/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:07:52 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/10 15:51:31 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_index(t_list *lst, int index)
{
	int	i;
	int	*ret;

	i = 0;
	while (i < index)
		lst = lst->next;
	ret = lst->content;
	return (*ret);
}

int	get_top(t_list *lst)
{
	int	*ret;

	ret = lst->content;
	return (*ret);
}

int	get_bottom(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst->content);
}

void	add_front(t_list **lst, int nb)
{
	ft_lstadd_front(lst, &nb);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:10:39 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 21:38:23 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_clear_top(t_list **lst)
{
	int		ret;
	t_list	*temp;

	ret = lst_get_top(*lst);
	temp = *lst;
	*lst = temp->next;
	free(temp->content);
	free(temp);
	return (ret);
}

int	lst_clear_bottom(t_list **lst)
{
	t_list	*stack;
	t_list	*temp;
	t_list	*temp2;
	int		ret;

	ret = lst_get_bottom(*lst);
	stack = *lst;
	temp = stack;
	temp2 = temp->next;
	while (temp2->next)
	{
		temp2 = temp2->next;
		temp = temp->next;
	}
	temp->next = NULL;
	*lst = stack;
	return (ret);
}

void	lst_add_front(t_list **lst, int nb)
{
	int	*ret;

	ret = malloc(1 * sizeof(int));
	ret[0] = nb;
	ft_lstadd_front(lst, ft_lstnew(ret));
}

void	lst_add_back(t_list **lst, int nb)
{
	int	*ret;

	ret = malloc(1 * sizeof(int));
	ret[0] = nb;
	ft_lstadd_back(lst, ft_lstnew(ret));
}
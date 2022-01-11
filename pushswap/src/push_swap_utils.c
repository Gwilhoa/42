/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:10:39 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 19:19:29 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	lst_clear_top(t_list **lst)
{
	int		ret;
	t_list	*temp;
	t_list	*stack;

	ret = lst_get_top(*lst);
	temp = *lst;
	stack = temp->next;
	lst = &stack;
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
	free(temp2->content);
	free(temp2);
	*lst = stack;
	return (ret);
}

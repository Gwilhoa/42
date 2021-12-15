/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:24:55 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/15 19:14:31 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	push(t_list **this, int i)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	head->content = i;
	head->next = *this;
	*this = head;
}

int	pop(t_list **this)
{
	int		i;
	t_list	*temp;

	temp = *this;
	i = temp->content;
	*this = temp->next;
	return (i);
}

void	rotate(t_list **this)
{
	int	elem;

	elem = pop(this);
	ft_lstadd_back(this, ft_lstnew(elem));
}

void	reverse(t_list **this)
{
	t_list *temp;
	t_list *temp1;
	int elem;

	temp = *this;
	temp1 = *this;
	temp = temp->next;
	while (temp->next != 0)
	{
		temp = temp->next;
		temp1 = temp1->next;
	}
	elem = temp->content;
	temp1->next = 0;
	push(this, elem);
}
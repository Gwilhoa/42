/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:24:55 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/17 00:20:33 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	pop(t_list **this)
{
	int		i;
	t_list	*temp;

	temp = *this;
	i = *(int *)temp->content;
	*this = temp->next;
	return (i);
}

void	push(t_list **this, int i)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = i;
	ft_lstadd_front(this, ft_lstnew(p));
}

void	swap(t_list **this)
{
	int	p1;
	int	p2;

	p1 = pop(this);
	p2 = pop(this);
	push(this, p1);
	push(this, p2);
}

void	trade(t_list **from, t_list **to)
{
	int	i;

	if (!from || !*from)
		return ;
	i = pop(from);
	push(to, i);
}

void	rotate(t_list **this)
{
	int		*i;
	t_list	*temp;

	i = malloc(sizeof(int));
	*i = pop(this);
	temp = ft_lstnew(i);
	ft_lstadd_back(this, temp);
}
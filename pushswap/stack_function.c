/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:24:55 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/15 13:14:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*newstack(int *i)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->content = i;
	stack->next = NULL;
	return (stack);
}

int	pop(t_stack *this, int *i)
{
	ft_printf("test\n");
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (0);
	head->content = i;
	head->next = this;
	this = head;
	return (1);
}

void	print(t_stack *this)
{
	t_stack	*temp;

	temp = this;
	while (temp->next)
	{
		ft_printf("%d \n", temp->content);
		temp = temp->next;
	}
	ft_printf("%d \n", temp->content);
}

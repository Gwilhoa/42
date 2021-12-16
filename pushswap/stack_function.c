/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:24:55 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/16 23:57:59 by gchatain         ###   ########.fr       */
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

void	display(t_list *stack1, t_list *stack2)
{
	while (stack1 || stack2)
	{
		if (!stack1)
		{
			ft_printf("  %d\n", *(int *)stack2->content);
			stack2 = stack2->next;
		}
		else if (!stack2)
		{
			ft_printf("%d  \n", *(int *)stack1->content);
			stack1 = stack1->next;
		}
		else
		{
			ft_printf("%d %d\n",
				*(int *)stack1->content, *(int *)stack2->content);
			stack1 = stack1->next;
			stack2 = stack2->next;
		}
	}
}

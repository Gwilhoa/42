/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/16 23:58:39 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main()
{
	t_list *stack1;
	t_list *stack2;
	int	i = 5;
	int j;
	stack2 = NULL;

	stack1 = ft_lstnew(&i);
	push(&stack1, 4);
	push(&stack1, 6);
	push(&stack1, 9);
	push(&stack1, 2);
	push(&stack1, 1);
	pop(&stack1);
	display(stack1, stack2);
	return 0;
}

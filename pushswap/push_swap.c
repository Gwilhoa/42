/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/17 00:07:28 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(void)
{
	t_list	*stack1;
	t_list	*stack2;
	int		i;
	int		j;

	i = 5;
	stack2 = NULL;
	stack1 = ft_lstnew(&i);
	push(&stack1, 4);
	push(&stack1, 6);
	push(&stack1, 9);
	push(&stack1, 2);
	push(&stack1, 1);
	swap(&stack1);
	display(stack1, stack2);
	return (0);
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

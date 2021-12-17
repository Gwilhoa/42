/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/17 12:19:11 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, const char *argv[])
{
	t_list	*stack1;
	t_list	*stack2;
	int		i;
	int		temp;

	stack2 = 0;
	stack1 = 0;
	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (temp == 0 && argv[i][0] != 48)
		{
			ft_printf("err0r");
			return 0;
		}
		push(&stack1, temp);
		i++;
	}
	display(stack1, stack2);
	return (argc);
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

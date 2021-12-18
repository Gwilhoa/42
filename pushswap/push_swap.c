/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/18 10:56:22 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, const char *argv[])
{
	char	str[3];
	t_list	*stack1;
	t_list	*stack2;

	stack2 = 0;
	stack1 = 0;
	if (init(&stack1, argv) == 0)
		return (0);
	display(stack1, stack2);
	read(1, str, 2);
	str[2] = 0;
	if (str[0] == 's')
	{
		ft_swap(&stack1, &stack2, str[1]);
	}
	display(stack1, stack2);
	return (argc);
}

void	display(t_list *stack1, t_list *stack2)
{
	ft_printf("---------------------\n");
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
	ft_printf("---------------------\n");
}

int	init(t_list **stack, const char **args)
{
	int	i;
	int	temp;

	i = 1;
	while (args[i] != 0)
	{
		temp = ft_atoi(args[i]);
		if (temp == 0 && args[i][0] != 48)
		{
			ft_printf("error");
			return (0);
		}
		push(stack, temp);
		i++;
	}
	return (1);
}

void	ft_swap(t_list **stack1, t_list **stack2, char c)
{
	if (c == 'a')
		swap(stack1);
	else if (c == 'b')
		swap(stack2);
	else if (c == 's')
	{
		swap(stack1);
		swap(stack2);
	}
}

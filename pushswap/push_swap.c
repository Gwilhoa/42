/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/15 13:07:35 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char const *argv[])
{
	ft_printf("test\n");
	t_stack	*stack;
	int i = 5;
	int j = 6;

	stack = newstack(&i);
	ft_printf("test\n");
	stack->pop(&j);
	ft_printf("test\n");
	stack->print();
	return 0;
}

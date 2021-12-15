/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:27 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/15 18:46:01 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main()
{
	t_list *stack1;
	t_list *stack2;

	stack1 = ft_lstnew(5);
	push(&stack1,7);
	push(&stack1,8);
	push(&stack1,2);
	push(&stack1,4);
	push(&stack1,3);
	return 0;
}

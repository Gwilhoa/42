/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 21:46:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	lst_add_front(&stacka, 1);
	lst_add_front(&stacka, 2);
	lst_add_front(&stacka, 3);
	lst_add_front(&stacka, 4);
	lst_add_front(&stacka, 5);
	lst_add_front(&stacka, 6);
	lst_add_front(&stacka, 7);
	lst_add_front(&stacka, 8);
	lst_add_front(&stacka, 9);
	reverse_rotate(&stacka);
	lst_display(stacka);
	return 0;
}

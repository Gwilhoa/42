/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/10 15:47:30 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(void)
{
	t_list *lst;
	int i = 15;

	lst = ft_lstnew(&i);
	add_front(&lst, 2);
	add_front(&lst, 5);
	add_front(&lst, 3);
	add_front(&lst, 12);
	add_front(&lst, 7);
	add_front(&lst, 6);
	add_front(&lst, 4);
	ft_printf("%d - %d", get_bottom(lst), get_top(lst), get_index(lst, 3));
	return 0;
}


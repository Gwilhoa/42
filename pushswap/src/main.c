/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/11 19:19:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int main(void)
{
	t_list	*lst;
	int i = 1;

	lst = ft_lstnew(&i);
	lst_add_front(&lst, 2);
	lst_add_front(&lst, 3);
	lst_add_front(&lst, 4);
	lst_add_front(&lst, 5);
	lst_add_front(&lst, 6);
	lst_add_front(&lst, 7);
	lst_add_front(&lst, 8);
	lst_add_front(&lst, 9);
	lst_clear_top(&lst);
	ft_printf("%d", lst_get_index(lst, 1));
	return 0;
}


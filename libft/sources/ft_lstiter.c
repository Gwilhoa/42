/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:37:54 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/31 22:42:41 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*t;

	if (!lst || !f)
		return ;
	t = lst;
	while (t)
	{
		f(t->content);
		t = t->next;
	}
}

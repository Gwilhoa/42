/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:18 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/08 11:07:18 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	if (!lst)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = t;
	}
}

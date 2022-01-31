/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:07:08 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/31 22:38:15 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*t;

	if (!lst)
		return (0);
	i = 0;
	t = lst;
	while (t)
	{
		t = t->next;
		i++;
	}
	return (i);
}

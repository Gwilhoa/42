/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:58:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/19 16:19:16 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		p;

	if (!s || c == 0)
		return (ft_strchr(s, c));
	str = (char *) s;
	i = 0;
	p = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = i;
		i++;
	}
	if (p == -1)
		return (0);
	return (str + p);
}

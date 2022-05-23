/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:05:42 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/07 10:36:05 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	s = ft_strlen(s2);
	str = malloc((i + s) * sizeof(char) + 2);
	if (!str)
		return (0);
	i = 0;
	s = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[s])
	{
		str[i + s] = s2[s];
		s++;
	}
	str[i + s] = 0;
	return (str);
}

char	*ft_strdup(char const *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(ft_strlen(src) + 1 * sizeof(char));
	if (!ret)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

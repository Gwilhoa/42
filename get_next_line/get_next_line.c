/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:25:15 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/18 16:25:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search(char *str, int charset)
{
	int	i;
	while (str[i])
	{
		if (str[i] == charset)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char static	*reste;
	char		str[BUFFER_SIZE + 1];
	char		*ret;
	int			r;
	int			n;

	if (reste)
		ret = reste;
	r = read(fd, str, BUFFER_SIZE);
	while (r > 0)
	{
		str[r] = '\0';
		n = ft_search(str, '\n');
		if (n != -1)
		{
			if (str + n + 1)
				reste = ft_strdup(str + n + 1);
			str[n + 1] = 0;
			return (ft_strjoin(ret, str));
		}
		ret = ft_strjoin(ret, str);
		r = read(fd, str, BUFFER_SIZE);
	}
	if (r == 0)
		return (ft_strjoin(ret, str));
	return (0);
}

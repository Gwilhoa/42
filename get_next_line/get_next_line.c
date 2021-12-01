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

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == charset)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		str[BUFFER_SIZE + 1];
	char		*ret;
	int			r;
	int			n;

	ret = "";
	if (reste)
		ret = reste;
	r = read(fd, str, BUFFER_SIZE);
	str[r] = '\0';
	while (r > 0)
	{
		ret = ft_strjoin(ret, str);
		n = ft_search(ret, '\n');
		if (n != -1)
		{
			free(reste);
			reste = ft_strdup(ret + n + 1);
			ret[n + 1] = 0;
			return (ret);
		}
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
	}
	return (0);
}

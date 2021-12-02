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
	char		*temp;
	int			r;

	ret = 0;
	if (reste)
	{
		free(ret);
		ret = ft_strdup(reste);
		free(reste);
		reste = NULL;
	}
	r = read(fd, str, BUFFER_SIZE);
	str[r] = '\0';
	while (r > 0)
	{
		if (!ret)
			ret = malloc(1);
		temp = ft_strjoin(ret, str);
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
		if (ft_search(ret, '\n') != -1)
		{
			temp = ft_strdup(ret + ft_search(ret, '\n') + 1);
			if (ft_strlen(temp) != 0)
				reste = ft_strdup(temp);
			free(temp);
			ret[ft_search(ret, '\n') + 1] = 0;
			return (ret);
		}
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
	}
	if (!ret)
		return (0);
	return (ret);
}

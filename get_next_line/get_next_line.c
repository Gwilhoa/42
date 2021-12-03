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

char	*ft_has_nl(char *ret, char *reste)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(ret + ft_search(ret, '\n') + 1);
	while (temp[i] != 0)
	{
		reste[i] = temp[i];
		i++;
	}
	free(temp);
	ret[ft_search(ret, '\n') + 1] = 0;
	return (ret);
}

char	*ft_init(char *ret, char *str)
{
	char	*temp;

	if (!ret)
	{
		ret = malloc(1);
		ret[0] = 0;
	}
	temp = ft_strjoin(ret, str);
	free(ret);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	reste[BUFFER_SIZE + 1];
	char		str[BUFFER_SIZE + 1];
	char		*ret;
	int			r;

	ret = 0;
	if (reste[0] != 0)
	{
		ret = ft_strdup(reste);
		reste[0] = 0;
	}
	r = read(fd, str, BUFFER_SIZE);
	while (r > 0 || (ret && ft_search(ret, '\n') != -1))
	{
		if (r == -1)
			return (0);
		str[r] = '\0';
		ret = ft_init(ret, str);
		if (ft_search(ret, '\n') != -1)
			return (ft_has_nl(ret, reste));
		r = read(fd, str, BUFFER_SIZE);
	}
	return (ret);
}

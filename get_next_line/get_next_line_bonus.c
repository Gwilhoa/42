/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:25:15 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/08 18:28:48 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_has_nl(char *ret, char **reste)
{
	char	*temp;

	temp = ft_strdup(ret + ft_search(ret, '\n') + 1);
	if (ft_strlen(temp) != 0)
		*reste = ft_strdup(temp);
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
	free(str);
	return (temp);
}

int	ft_reader(char **str, int fd)
{
	char	*temp;
	int		r;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, temp, BUFFER_SIZE);
	*str = temp;
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*reste[OPEN_MAX];
	char		*str;
	char		*ret;
	int			r;

	ret = 0;
	if (fd >= 0 && reste[fd])
	{
		ret = ft_strdup(reste[fd]);
		free(reste[fd]);
		reste[fd] = NULL;
	}
	r = ft_reader(&str, fd);
	while (r > 0 || (ret && ft_search(ret, '\n') != -1))
	{
		if (r < 0)
			return (0);
		str[r] = '\0';
		ret = ft_init(ret, str);
		if (ft_search(ret, '\n') != -1)
			return (ft_has_nl(ret, &reste[fd]));
		r = ft_reader(&str, fd);
	}
	free(str);
	return (ret);
}

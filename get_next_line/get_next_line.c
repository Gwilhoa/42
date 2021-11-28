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

char	*ft_resetret(char *str, char **reste)
{
	char	*ret;

	ret = ft_strjoin(*reste, str);
	free(*reste);
	*reste = NULL;
	free(str);
	return (ret);
}

char	*ft_hasnewline(int i, char *str, char **reste)
{
	if (str[i] == 0)
		return(*reste);
	if (*reste)
		free(*reste);
	*reste = ft_strdup(str + i + 1);
	str[i + 1] = '\0';
	return (str);
}

char	*reader(int fd, char *temp, char **reste)
{
	int			i;
	int			r;
	char		*str;

	if (temp)
	{
		str = strdup(temp);
		free(temp);
	}
	else {
		str = malloc((BUFFER_SIZE) * sizeof(char *));
		r = read(fd, str, BUFFER_SIZE);
	}
	i = 0;
	if (*reste != NULL)
		str = ft_resetret(str, &*reste);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n' || str[i] == 0)
			return (ft_hasnewline(i, str, &*reste));
		i++;
	}
	temp = ft_fullret(r, str, fd, &*reste);
	free(str);
	return (temp);
}

char	*ft_fullret(int r, char *str, int fd, char **reste)
{
	char	*temp;
	char	*plus;

	if (r < BUFFER_SIZE)
		return (str);
	if (r == BUFFER_SIZE)
	{
		temp = reader(fd, 0, &*reste);
		if (temp)
			plus = ft_strjoin(str, temp);
		else
			return (str);
		free(temp);
		return (plus);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*reste;

	str = malloc(sizeof(char *) * BUFFER_SIZE);
	read(fd, str, BUFFER_SIZE);
	if (!str || (ft_strlen(str) == 0 && !reste))
		return (0);
	return (reader(fd, str, &reste));
}

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

#ifndef BUFFER_SIZE

#define BUFFER_SIZE 1

#endif










char	*resetret(char **reste, char *str)
{
	char	*temp;

	temp = ft_strjoin(*reste, str);
	free(str);
	free(*reste);
	*reste = NULL;
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*reste;
	int			r;
	char		*str;

	str = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	r = read(fd, str, BUFFER_SIZE);
	if (fd < 0 || reste == NULL || ft_strlen(str) == 0 || r < 1)
	{
		free(str);
		return (0);
	}
	return (reader(fd, str, &reste));
}

char	*reader(int fd, char *str, char **reste)
{
	int		ret;
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!str)
	{
		str = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		ret = read(fd, str, BUFFER_SIZE);
		if (ret < 0)
			return (0);
		if (ret == 0)
			return (str);
	}
	str[BUFFER_SIZE + 1] = '\0';
	if (*reste)
		str = resetret(&*reste, str);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*reste = ft_strdup(str + i + 1);
			str[i + 1] = 0;
			return (str);
		}
		i++;
	}
	temp2 = reader(fd, 0, *&reste);
	temp = ft_strjoin(str, temp2);
	free(temp2);
	free(str);
	return (temp);
}

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

char	*ft_hasnewline(int i, int r, char *str, char **reste)
{
	if (str[i] == 0)
		return(*reste);
	*reste = ft_strdup(str + i + 1);
	str[i + 1] = '\0';
	return (ft_strdup(str));
}

char	*get_next_line(int fd)
{
	int			i;
	int			r;
	char		*str;
	char		*temp;
	static char	*reste;

	if (!BUFFER_SIZE)
		return (0);
	i = 0;
	str = malloc((BUFFER_SIZE) * sizeof(char *));
	r = read(fd, str, BUFFER_SIZE);
	if (reste != NULL)
		str = ft_resetret(str, &reste);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
		{
			
			temp = ft_hasnewline(i, r, str, &reste);
			free(str);
			return (temp);
		}
		i++;
	}
	temp = ft_fullret(r, &str, fd, &reste);
	if (!temp)
		return(str);
	free(str);
	return (temp);
}

char	*ft_fullret(int r, char **str, int fd, char **reste)
{
	char	*temp;
	char	*plus;
	if (r == BUFFER_SIZE)
	{
		temp = get_next_line(fd);
		plus = ft_strjoin(*str, temp);
		temp = NULL;
		return (plus);
	}
	return (0);
}


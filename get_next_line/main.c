/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:21:00 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/19 19:39:38 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char	*strjoin_gch(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	i = strlen(s1);
	s = strlen(s2);
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

int	main(void)
{
	int		rd;
	int		fd;
	char	*str;
	char	*file;

	file = strjoin_gch("recits/", DIRSET);
	rd = open(DIRSET, O_WRONLY);
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	free(file);
	while (str)
	{
		dprintf(rd, "%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

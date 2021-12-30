/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:57:36 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/24 15:40:22 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_hasnl(const char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int i = 0;
	int j = 0;

	str = malloc(sizeof(char) + (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(char const *str)
{
	char	*ret;
	int		i = 0;

	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
char	*get_next_line(int fd)
{
	static char *rest;
	char *ret;
	char *str;
	int r = 1;

	ret = 0;
	if (rest != 0)
	{
		ret = ft_strdup(rest);
	}
	while (r > 0 || (ret && ft_hasnl(ret) != -1))
	{
		if (!ret || ft_hasnl(ret) == -1)
		{
			str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			r = read(fd, str, BUFFER_SIZE);
			if (r == -1)
				return (0);
			if (r == 0 && ret)
				return ret;
			if (r == 0 && !ret)
				return 0;
			str[r] = 0;
			if (!ret)
				ret = malloc(0);
			ret = ft_strjoin(ret, str);
		}
		if (ret && ft_hasnl(ret) != -1)
		{
			rest = ft_strdup(ret + ft_hasnl(ret) + 1);
			ret[ft_hasnl(ret) + 1] = 0;
			return (ret);
		}
	}
	return (ret);
}

int main(int argc, char const *argv[])
{
	char *str;
	int fd = open("test.txt", O_RDONLY);

	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	return 0;
}

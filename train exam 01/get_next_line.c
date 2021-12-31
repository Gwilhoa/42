/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:25:15 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/31 09:12:00 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	s = ft_strlen(s2);
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
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strdup(char const *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(ft_strlen(src) + 1 * sizeof(char));
	if (!ret)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

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
	static char	rest[BUFFER_SIZE + 1];
	char		*str;
	char		*ret;
	char		*temp;
	int			r;
	int			i;

	ret = 0;
	if (fd >= 0 && *rest)
	{
		ret = ft_strdup(rest);
		*rest = 0;
	}
	r = 1;
	while (r > 0 || (ret && ft_search(ret, '\n') != -1))
	{
		if (!ret || ft_search(ret, '\n') == -1)
		{
			str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			r = read(fd, str, BUFFER_SIZE);
			if (r <= 0)
			{
				free(str);
				return (ret);
			}
			str[r] = '\0';
			if (!ret)
			{
				ret = malloc(1);
				ret[0] = 0;
			}
			ret = ft_strjoin(ret, str);
			if (!ret)
				return (0);
		}
		if (ret && ft_search(ret, '\n') != -1)
		{
			i = 0;
			temp = ret + ft_search(ret, '\n') + 1;
			while (temp[i] != 0)
			{
				rest[i] = temp[i];
				i++;
			}
			rest[i] = 0;
			ret[ft_search(ret, '\n') + 1] = 0;
			return (ret);
		}
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	int fd = open("odyssey_du_b2k.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str= get_next_line(fd);
		printf("%s",str);
	}
	free(str);
	
	return 0;
}

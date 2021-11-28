/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:24:06 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/29 15:18:35 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *str, char *ret)
{
	int		i;
	int		j;

	i = ft_strlen(ret);
	j = 0;
	while (str[j] != '\0')
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = '\0';
}

int	array_len(int size, char **strs)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ret;

	if (size == 0)
		return (malloc(0));
	ret = malloc(ft_strlen(sep) * size + 1
			+ array_len(size, strs) * sizeof(char));
	if (!ret)
		return (0);
	ret[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_putstr(strs[i], ret);
		i++;
		if (i != size)
			ft_putstr(sep, ret);
	}
	ft_strcat(ret, "\0");
	return (ret);
}

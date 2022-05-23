/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 08:40:49 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/16 08:08:44 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str)
	{
		if (*str == to_find[i])
		{
			i++;
			if (!to_find[i])
				return (str - ft_strlen(to_find) + 1);
		}
		else if (i > 0)
			i = 0;
		str++;
	}
	return (0);
}

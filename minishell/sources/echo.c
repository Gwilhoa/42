/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:23:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/22 13:23:12 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int		i;
	STRING	ret;

	i = 1;
	ret = malloc(1);
	ret[0] = 0;
	while (args[i] != 0 && ft_strncmp(args[i], ">", ft_strlen(args[i])) != 0)
	{
		if (i != 1)
			ret = ft_strjoin(ret, " "); //leaks 
		ret = ft_strjoin(ret, args[i]); //leaks
		i++;
	}
	if (ft_strncmp(args[i], ">", ft_strlen(args[i])) == 0)
	{
		if (args[i + 1] == 0)
			return (0);
	}
	ft_printf("%s\n", ret);
	return (1);
}

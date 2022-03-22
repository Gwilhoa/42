/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/22 14:30:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	STRING	line;
	STRING	*args;
	char	dir[256];
	STRING	prompt;

	while (1)
	{
		getcwd(dir, sizeof(dir));
		prompt = ft_strjoin("minishell ", dir);
		prompt = ft_strjoin(prompt, " >> "); // leaks
		line = readline(prompt);
		if (line[0] != 0)
		{	
			add_history(line);
			args = ft_split(line, ' ');
			if (getcmd(args) == 0)
				ft_printf("%sminishell: %s:command not found\n%s", RED, line, WHITE);
		}
	}
	return (0);
}

int	getcmd(char **args)
{
	if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0)
		return (ft_pwd());
	return (0);
}

int	ft_pwd(void)
{
	char	dir[256];

	getcwd(dir, sizeof(dir));
	ft_printf("%s\n", dir);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/04 11:33:21 by gchatain         ###   ########lyon.fr   */
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
			{
				ft_printf("%sminishell: %s", RED, line);
				ft_printf("command not found\n%s", WHITE);
			}
		}
	}
	return (0);
}

/**
 * @brief program's center
 * 
 * @param args argument's command
 * @return int (return 0 if the command does'nt exist)
 */
int	getcmd(char **args)
{
	t_cmd	cmd;

	cmd = ft_init(args);
	return (0);
}

/**
 * @brief function bash pwd
 * 
 * @return int (1 if success)
 */
int	ft_pwd(void)
{
	char	dir[256];

	getcwd(dir, sizeof(dir));
	ft_printf("%s\n", dir);
	return (1);
}

/**
 * @brief function to know if the string is a redirecting bash
 * 
 * @param str (at comparate)
 * @return int (1 is redirecting)
 */
int	ft_isredirecting(const STRING str)
{
	if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<<", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

/**
 * @brief initalization of struct cmd (parsing)
 * if the bonuses are to be done, modify the structure in structure list
 * @param args 
 * @return t_cmd 
 */
t_cmd	ft_init(char	**args)
{
	t_cmd	cmd;
	int		i;

	if (ft_isredirecting(args[0]) == 1)
	{
		cmd.redirecting = args[1]);
		cmd.redirecting_tag = args[0];
		cmd.cmd = args[2];
		cmd.args = args;//
	}
	else
	{
		cmd.redirecting = 1;//
		cmd.cmd = args[0];
		cmd.args = args;
	}
}
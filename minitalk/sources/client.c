/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:42 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/01 09:15:17 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putstr_fd("successfully received (", 1);
		ft_putnbr_fd(received, 1);
		ft_putstr_fd(" chars)", 1);
		exit(0);
	}
}

static void	sender(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	if (ft_atoi(argv[1]) < 0)
		return (ft_putstr_fd("le pid ne peut pas etre négatif", 1));
	sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}

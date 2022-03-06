/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:16:54 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/02 13:31:57 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <time.h>
# include <pthread.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_philosophers
{
	int				last_eat;
	pthread_t		thread;
	pthread_mutex_t	time;
	int				fork;
}	t_philosophers;

typedef struct s_table
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				each_time_to_eat;

	t_philosophers	*philos;

}	t_table;

int		ft_printf(const char *str, ...);
int		function_parser(va_list args, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putunsigned(unsigned int nb, int fd);
int		ft_putchangebase(unsigned int nbr, const char *base, int fd);
int		ft_putpointer(unsigned long long nbr, int fd);
void	*routine(void *vargp);

#endif
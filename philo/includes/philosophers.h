/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:16:54 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/11 08:47:35 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include <stdarg.h>
# include <unistd.h>

struct	s_table;

typedef struct s_philosophers
{
	int				number;
	int				last_eat;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_table
{
	int				number_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				each_time_to_eat;

	t_philo			*philos;

}	t_table;

t_philo	init_philo(t_table **table);
int		ft_atoi(char const *str);
int		ft_printf(const char *str, ...);
int		function_parser(va_list args, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putunsigned(unsigned int nb, int fd);
int		ft_putchangebase(unsigned int nbr, const char *base, int fd);
int		ft_putpointer(unsigned long long nbr, int fd);
int		init(const char **argv, t_table *table);
void	*routine(void *vargp);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:59:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/11 16:22:52 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		eats(philo);
		usleep(philo->table->time_to_eat);
	}
}

void	eats(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->fork;
	if (philo->number == philo->table->number_philo)
		right_fork = &philo->table->philos[0].fork;
	else
	{
		right_fork = &philo->table->philos[philo->number + 1].fork;
	}
	pthread_mutex_lock(left_fork);
	printf("%p\n",left_fork);
	talking(philo, TAKEN_FORK);
	pthread_mutex_lock(right_fork);
	printf("%p\n",right_fork);
	talking(philo, THINKING);
	talking(philo, EAT);
	usleep(philo->table->time_to_eat);
	talking(philo, SLEEP);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
}

void	talking(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->table->talking);
	if (type == TAKEN_FORK)
		ft_printf("[%d] philo %i has taken left(la leurs) fork\n", get_time() - philo->table->start_time, philo->number);
	if (type == EAT)
		ft_printf("[%d] philo %i is eating\n", get_time() - philo->table->start_time, philo->number);
	if (type == SLEEP)
		ft_printf("[%d] philo %i is sleeping\n", get_time() - philo->table->start_time, philo->number);
	if (type == THINKING)
		ft_printf("[%d] philo %i has taken right fork\n", get_time() - philo->table->start_time, philo->number);
	pthread_mutex_unlock(&philo->table->talking);
}

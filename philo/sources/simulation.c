/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:59:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/15 14:51:27 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	philo = (t_philo *) arg;
	left_fork = &philo->fork;
	if (philo->number == philo->table->number_philo)
		right_fork = &philo->table->philos[0].fork;
	else
		right_fork = &philo->table->philos[philo->number].fork;
	while (philo->table->start_time != (u_int64_t)-1)
	{
		talking(philo, THINKING);
		taking_fork(philo, left_fork);
		taking_fork(philo, right_fork);
		talking(philo, EAT);
		philo->last_eat = get_time() - philo->table->start_time;
		my_usleep(philo->table->time_to_eat);
		philo->each_eaten++;
		talking(philo, SLEEP);
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
		my_usleep(philo->table->time_to_sleep);
	}
	return (0);
}

void	taking_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	talking(philo, TAKEN_FORK);
}

void	talking(t_philo *philo, int type)
{
	int			number;
	u_int64_t	time;

	number = philo->number;
	pthread_mutex_lock(&philo->table->talking);
	if (philo->table->start_time == (u_int64_t)-1)
	{
		pthread_mutex_unlock(&philo->table->talking);
		return ;
	}
	time = get_time() - philo->table->start_time;
	if (type == TAKEN_FORK)
		ft_printf("[%i] philo %i has taken fork\n", time, number);
	if (type == EAT)
		ft_printf("[%i] philo %i is eating\n", time, number);
	if (type == SLEEP)
		ft_printf("[%i] philo %i is sleeping\n", time, number);
	if (type == THINKING)
		ft_printf("[%i] philo %i has thinking\n", time, number);
	if (type == DEATH)
		ft_printf("[%i] philo %i died\n", time, number);
	pthread_mutex_unlock(&philo->table->talking);
}

void	my_usleep(u_int64_t time)
{
	u_int64_t	start;

	start = get_time();
	while (start + time > get_time())
	{
		usleep(100);
	}
	return ;
}

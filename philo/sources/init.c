/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:54:58 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/15 15:15:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_table(t_table **table, const char **argv)
{
	t_table	*ret;

	ret = *table;
	ret->number_philo = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&ret->talking, NULL);
	*table = ret;
}

int	init(const char **argv, t_table *table, int argc)
{
	int	i;

	init_table(&table, argv);
	if (argc == 5)
		table->each_time_to_eat = -1;
	else
		table->each_time_to_eat = ft_atoi(argv[5]);
	i = 0;
	table->philos = malloc(table->number_philo * sizeof(t_philo));
	while (i < table->number_philo)
	{
		table->philos[i] = init_philo(&table, i);
		i++;
	}
	table->start_time = get_time();
	launch_thread(&table);
	return (1);
}

t_philo	init_philo(t_table **table, int i)
{
	t_philo	philo;

	philo.last_eat = 0;
	philo.number = i + 1;
	philo.each_eaten = 0;
	pthread_mutex_init(&philo.fork, NULL);
	philo.table = *table;
	return (philo);
}

int	verif_philo(t_philo *philo)
{
	if (philo->last_eat != philo->table->time_to_die
		&& get_time() - philo->table->start_time
		> philo->last_eat + philo->table->time_to_die)
		return (1);
	if (philo->table->each_time_to_eat != -1
		&& has_eaten(philo->table) == philo->table->number_philo)
		return (2);
	return (0);
}

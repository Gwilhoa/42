/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:49:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/11 08:51:07 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if (argc == 5 || argc == 6 && verif_args(argv) == 1)
	{
		if (!init(argv, &table))
			return (ft_putstr_fd("error", 1));
	}
	else
		return (ft_putstr_fd("./philo [number philo] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]",1));
	return (0);
}

int	init(const char **argv, t_table *table)
{
	int	i;

	table->number_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->each_time_to_eat = ft_atoi(argv[5]);
	i = 0;
	table->philos = malloc(table->number_philo * sizeof(t_philo));
	while (i <= table->number_philo)
	{
		table->philos[i] = init_philo(&table);
		i++;
	}
	return (1);
}

t_philo	init_philo(t_table **table)
{
	t_philo	philo;

	philo.last_eat = 0;
	philo.table = table;
	pthread_create(&philo.thread, NULL, routine, &philo);
	return (philo);
}

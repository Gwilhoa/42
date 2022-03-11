/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:49:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/11 15:54:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if ((argc == 5 || argc == 6) && verif_args(argv, argc) == 1)
	{
		if (!init(argv, &table, argc))
			return (ft_putstr_fd("error", 1));
	}
	else
		return (ft_putstr_fd("./philo [number philo] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]", 1));
	return (0);
}

int	init(const char **argv, t_table *table, int argc)
{
	int	i;

	table->number_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&table->talking, NULL);
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
	i = 0;
	while (i < table->number_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		i++;
	}
	while (1)
	{
	}
	return (1);
}

t_philo	init_philo(t_table **table, int i)
{
	t_philo	philo;

	philo.last_eat = 0;
	philo.number = i + 1;
	pthread_mutex_init(&philo.fork, NULL);
	philo.table = *table;
	return (philo);
}

int	verif_args(const char **argv, int argc)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(argv[i], temp, ft_strlen(argv[i])))
		{
			free(temp);
			return (0);
		}
		i++;
		free(temp);
	}
	return (1);
}

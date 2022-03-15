/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:49:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/15 14:53:16 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const *argv[])
{
	t_table		table;
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	if ((argc == 5 || argc == 6) && verif_args(argv, argc) == 1)
	{
		init(argv, &table, argc);
		while (1)
		{
			if (verif_philo(&table.philos[i]) == 1)
				return (stop(&table, i + 1));
			if (verif_philo(&table.philos[i]) == 1)
				return (stop(&table, -1));
			i++;
			if (i >= table.number_philo)
				i = 0;
		}
	}
	else
	{
		ft_putstr_fd("./philo [number philo] [time_to_die]", 1);
		ft_putstr_fd("[time_to_eat] [time_to_sleep]", 1);
		ft_putstr_fd("[number_of_times_each_philosopher_must_eat]", 1);
	}
	return (0);
}

int	stop(t_table *table, int philo)
{
	int			i;
	u_int64_t	time;

	time = get_time() - table->start_time;
	table->start_time = (u_int64_t)-1;
	i = 0;
	while (i < table->number_philo)
	{
		pthread_mutex_unlock(&table->philos[i].fork);
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	if (philo != -1)
		ft_printf("[%i] philo %i died\n", time, philo);
	else
		ft_printf("[%i] dinner is over\n", time);
	free(table->philos);
	return (0);
}

int	has_eaten(t_table *table)
{
	int	nb;
	int	i;
	int	ret;

	nb = table->number_philo;
	i = 0;
	ret = 0;
	while (i < nb)
	{
		if (table->philos[i].each_eaten >= table->each_time_to_eat)
			ret++;
		i++;
	}
	return (ret);
}

void	launch_thread(t_table **table)
{
	t_table	*ret;
	t_philo	*philo;
	int		i;

	i = 0;
	ret = *table;
	philo = ret->philos;
	while (i < ret->number_philo)
	{
		if (i % 2 == 0)
			pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	usleep(100);
	while (i < ret->number_philo)
	{
		if (i % 2 != 0)
			pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	*table = ret;
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

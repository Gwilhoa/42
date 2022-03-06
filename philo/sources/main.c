/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:49:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/06 14:21:41 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int main(int argc, char const *argv[])
{
	if (argc == 4 || argc == 5)
	{
		
	} else {
		return (ft_printf("./philo [number philo] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]"));
	}
	return (0);
}

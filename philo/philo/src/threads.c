/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:40:05 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:29:49 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, philos))
	{
		printf("Error: Monitor thread creation failed\n");
		return (1);
	}
	while (++i < data->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
		{
			printf("Error: Thread creation failed\n");
			return (1);
		}
	}
	return (0);
}

static int	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			printf("Error: Thread join failed\n");
			return (1);
		}
	}
	if (pthread_join(data->monitor_thread, NULL))
	{
		printf("Error: Monitor thread join failed\n");
		return (1);
	}
	return (0);
}

int	start_simulation(t_data *data, t_philo *philos)
{
	if (create_threads(data, philos))
		return (1);
	if (join_threads(data, philos))
		return (1);
	return (0);
}


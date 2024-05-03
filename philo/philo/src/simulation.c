/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:52:36 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 11:56:22 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*handle_one_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	print_message(philo, "has taken a fork");
	ft_usleep_ms(philo->data->die_time);
	print_message(philo, "died");
	return (NULL);
}

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
		return (handle_one_philo(philo));
	while (!philo->data->dead)
	{
		think(philo);
		pick_up_forks(philo);
		if (!philo->data->dead)
		{
			eat(philo);
			put_down_forks(philo);
			sleep_philo(philo);
		}
		else
		{
			put_down_forks(philo);
		}
	}
	return (NULL);
}

int	start_simulation(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philos))
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
	if (pthread_join(monitor_thread, NULL))
	{
		printf("Error: Monitor thread join failed\n");
		return (1);
	}
	i = -1;
	while (++i < data->philo_count)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			printf("Error: Thread join failed\n");
			return (1);
		}
	}
	return (0);
}

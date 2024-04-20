/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:52:36 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/20 12:05:27 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		// Think
		printf("Philo %d is thinking\n", philo->id);
		philo->last_eat = get_time();
		// Try to pick up left fork
		if (philo->id % 2)
		{
			pthread_mutex_lock(&philo->left_fork.mutex);
			pthread_mutex_lock(&philo->right_fork.mutex);
		}
		else
		{
			pthread_mutex_lock(&philo->right_fork.mutex);
			pthread_mutex_lock(&philo->left_fork.mutex);
		}
		// Eat
		printf("Philo %d is eating\n", philo->id);
		philo->eat_count++;
		sleep(philo->data->eat_time);
		// Put down right fork
		pthread_mutex_unlock(&philo->right_fork.mutex);
		// Put down left fork
		pthread_mutex_unlock(&philo->left_fork.mutex);
		// Sleep
		printf("Philo %d is sleeping\n", philo->id);
		sleep(philo->data->sleep_time);
	}
	return (NULL);
}

int	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		// Create a new thread
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
		{
			printf("Error: Thread creation failed\n");
			return (1);
		}
	}
	i = -1;
	while (++i < data->philo_count)
	{
		// Wait for the thread to finish
		if (pthread_join(philos[i].thread, NULL))
		{
			printf("Error: Thread join failed\n");
			return (1);
		}
	}
	return (0);
}

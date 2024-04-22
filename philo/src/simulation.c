/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:52:36 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/22 17:51:28 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_routine(void *arg)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)arg;
	while (!philo->data->dead)
	{
		if (check_if_philo_died(philo) || check_death(philo))
			break ;
		think(philo);
		if (check_if_philo_died(philo) || check_death(philo))
			break ;
		pick_up_forks(philo);
		if (check_if_philo_died(philo) || check_death(philo))
			break ;
		eat(philo);
		gettimeofday(&time, NULL);
		philo->last_eat = time;
		put_down_forks(philo);
		if (check_if_philo_died(philo) || check_death(philo))
			break ;
		sleep_philo(philo);
		if (check_if_philo_died(philo) || check_death(philo))
			break ;
	}
	return (NULL);
}

int	start_simulation(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
		{
			printf("Error: Thread creation failed\n");
			return (1);
		}
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

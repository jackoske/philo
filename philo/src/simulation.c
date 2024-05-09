/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:18:20 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 19:28:01 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	if_there_is_one_philo(t_philos *philo)
{
	if (philo->data.n_philos == 1)
	{
		philo->time = get_time();
		if (pthread_create(&(philo->philo), NULL, &routine_for_one, philo))
		{
			pthread_mutex_lock(philo->write);
			printf("Philosopher %d thread failed to be created\n", 1);
			return (0);
		}
		return (0);
	}
	return (1);
}

int	start_philosophers(t_philos *philosophers)
{
	int	i;

	i = 0;
	if (!if_there_is_one_philo(philosophers))
		return (0);
	while (i < philosophers->data.n_philos)
	{
		philosophers[i].time = get_time();
		philosophers[i].time_of_last_meal = philosophers[i].time;
		if (pthread_create(&((philosophers[i]).philo), NULL, &routine,
				&philosophers[i]) || pthread_detach(philosophers[i].philo))
		{
			pthread_mutex_lock(philosophers->write);
			printf("philosopher %d was not created!!!\n", i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_time_to_starve(t_philos *philo)
{
	if ((get_time() - philo->time_of_last_meal) >= philo->data.time_to_starve)
	{
		pthread_mutex_lock(philo->write);
		pthread_mutex_lock(philo->die);
		*(philo->check_die) = 0;
		printf("%lldms philo %d died 😵\n",
			(get_time() - philo->time), philo->id);
		pthread_mutex_unlock(philo->die);
	}
}

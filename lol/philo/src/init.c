/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:55 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 18:53:14 by Jskehan          ###   ########.fr       */
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

int	init_philo(t_philos *philos, t_data philo_info)
{
	int	i;

	i = 0;
	philos->check_die = (int *)malloc(sizeof(int));
	philos->count_meal = (int *)malloc(sizeof(int));
	if (philos->check_die == NULL || philos->count_meal == NULL)
		return (write(1, "Error: Failed to allocate memory "
				"for philosopher status.\n", 58));
	philos->check_die[0] = 1;
	philos->count_meal[0] = 0;
	while (i < philo_info.n_philos)
	{
		philos[i].data = philo_info;
		philos[i].id = i + 1;
		philos[i].check_die = philos[0].check_die;
		philos[i].count_meal = philos[0].count_meal;
		i++;
	}
	if (init_forks(philos) || init_mutex(philos))
		return (1);
	return (0);
}

int	init_forks(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.n_philos)
	{
		philo[i].left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].left_fork == NULL)
			return (write(1,
					"Error: Failed to allocate memory for left fork.\n", 48));
		pthread_mutex_init(philo[i].left_fork, NULL);
		i++;
	}
	i = 0;
	while (i < philo->data.n_philos)
	{
		if (i == 0)
			philo[i].right_fork = philo[philo->data.n_philos - 1].left_fork;
		else
			philo[i].right_fork = philo[i - 1].left_fork;
		i++;
	}
	return (0);
}

int	init_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	philos->write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->die = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->meals = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philos->write == NULL || philos->die == NULL || philos->meals == NULL)
		return (write(1, "Error: Failed to allocate memory for mutexes.\n",
				47));
	pthread_mutex_init(philos->write, NULL);
	pthread_mutex_init(philos->die, NULL);
	pthread_mutex_init(philos->meals, NULL);
	while (i < philos->data.n_philos)
	{
		philos[i].write = philos->write;
		philos[i].die = philos->die;
		philos[i].meals = philos->meals;
		i++;
	}
	return (0);
}

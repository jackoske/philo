/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:59:18 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/23 11:25:59 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
int check_death(t_philo *philo)
{
		pthread_mutex_lock(&philo->data->dead_mutex);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->dead_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (0);
}


//checks if current philo is dead
int philo_dead(t_philo *philo)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	if (ft_get_time_diff(philo->last_eat, current_time) > philo->data->die_time)
	{
		print_message(philo, "died");
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	return (0);
}
//check if any philo is dead
int check_all(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->philo_count)
	{
		print_message(&philos[i], "is dead");
		if (philo_dead(&philos[i]))
			return (1);
	}
	return (0);
}
//checks if philo ate number of meals in data compared to eat_count
int check_if_all_ate(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->philo_count)
	{
		if (philos[i].eat_count < philos->data->eat_count)
			return (0);
	}
	pthread_mutex_lock(&philos->data->dead_mutex);
	philos->data->dead = 1;
	pthread_mutex_unlock(&philos->data->dead_mutex);
	return (1);
}

void *monitor_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		printf("monitor\n");
		printf("dead: %d\n", philos->data->dead);
		printf("eat_count: %d\n", philos->data->eat_count);
		if (check_if_all_ate(philos) || check_all(philos))
			break ;
	}
	return (arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:59:18 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 11:57:13 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_philo *philo)
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

// checks if current philo is dead
int	philo_dead(t_philo *philo)
{
	struct timeval	current_time;

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
// check if any philo is dead
int	check_all(t_philo *philos)
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
// checks if philo ate number of meals in data compared to eat_count
int	check_if_all_ate(t_philo *philos)
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

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (check_if_philo_died(&data->philos[i]))
			{
				data->dead = 1;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

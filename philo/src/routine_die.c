/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:59:18 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/22 16:07:12 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_if_philo_died(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if ((time.tv_sec - philo->last_eat.tv_sec) * 1000 + (time.tv_usec
			- philo->last_eat.tv_usec) / 1000 > philo->data->die_time)
	{
		print_message(philo, "died");
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	return (0);
}
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

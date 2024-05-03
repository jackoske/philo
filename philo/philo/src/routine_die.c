/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:59:18 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:01:32 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_anyone_dead(t_philo *philo)
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

int	check_death(t_philo *philo)
{
	int	time;

	time = ft_get_time(philo->last_eat);
	if (time > philo->data->die_time)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		if (!philo->data->dead)
		{
			print_message(philo, "died");
			pthread_mutex_unlock(&philo->data->dead_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:06:01 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:32:37 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philos->data->philo_count)
		{
			pthread_mutex_lock(&philos[i].data->dead_mutex);
			if (ft_get_time(philos[i].last_eat) > philos[i].data->die_time)
			{
				print_message(&philos[i], "died");
				philos[i].data->dead = 1;
				pthread_mutex_unlock(&philos[i].data->dead_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].data->dead_mutex);
		}
		if (philos->eat_count == philos->data->num_of_meals)
		{
			pthread_mutex_lock(&philos->data->dead_mutex);
			philos->data->dead = 1;
			pthread_mutex_unlock(&philos->data->dead_mutex);
			return (NULL);
		}
	}
	return (NULL);
}
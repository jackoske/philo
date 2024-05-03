/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:51:33 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 16:53:30 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	t_philo	*philo;

	data = (t_data *)arg;
	while (data->dead == 0)
	{
		i = 0;
		while (i < data->philo_count)
		{
			philo = &data->philos[i];
			if (data->dead == 0 && philo->eat_count < data->num_of_meals
				&& get_time_diff_ms(philo->last_eat) > data->die_time)
			{
				data->dead = 1;
				print_message(data, "died");
			}
			i++;
		}
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_data	*data;
	int		index;
	t_philo	*philo;

	data = (t_data *)arg;
	index = data->current_index;
	philo = &data->philos[index];
	while (data->dead == 0 && (data->num_of_meals == -1
			|| philo->eat_count < data->num_of_meals))
	{
		think(data);
		eat(data, philo);
		philo_sleep(data);
	}
	return (NULL);
}

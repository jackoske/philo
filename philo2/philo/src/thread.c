/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:06:01 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 13:23:50 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->current_index = i;
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine, data))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data))
		return (1);
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->current_index = i;
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
}

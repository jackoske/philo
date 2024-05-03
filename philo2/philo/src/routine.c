/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:51:33 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 13:19:32 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor_routine(void *arg)
{
	t_data			*data;
	int				i;
	struct timeval	current_time;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			gettimeofday(&current_time, NULL);
			if ((current_time.tv_sec - data->philos[i].last_eat.tv_sec) * 1000
				+ (current_time.tv_usec - data->philos[i].last_eat.tv_usec)
				/ 1000 > data->die_time)
			{
				data->dead = 1;
				print_message(data, &data->philos[i], "died");
				return (NULL);
			}
			if (data->philos[i].eat_count >= data->num_of_meals)
			{
				data->dead = 1;
				return (NULL);
			}
			i++;
		}
		usleep(100);
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
	while (data->dead == 0 && philo->eat_count < data->num_of_meals)
	{
		print_message(data, philo, "is thinking");
		pick_up_forks(philo);
		print_message(data, philo, "is eating");
		philo->eat_count++;
		usleep(data->eat_time * 1000);
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		print_message(data, philo, "is sleeping");
		usleep(data->sleep_time * 1000);
	}
	return (NULL);
}

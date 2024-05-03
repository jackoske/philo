/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:52:36 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:24:35 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*handle_one_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	print_message(philo, "has taken a fork");
	ft_usleep_ms(philo->data->die_time);
	print_message(philo, "died");
	return (NULL);
}


void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
		return (handle_one_philo(philo));
	while (philo->data->dead == 0 
		&& (philo->eat_count < philo->data->num_of_meals || philo->data->num_of_meals == -1))
	{
		think(philo);
		pick_up_forks(philo);
		eat(philo);
		put_down_forks(philo);
		sleep_philo(philo);
	}
	return (NULL);
}



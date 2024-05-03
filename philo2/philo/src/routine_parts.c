/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:59:18 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 16:54:36 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void think(t_data *data)
{
	print_message(data, "is thinking");
}

void eat(t_data *data, t_philo *philo)
{
	pick_up_forks(philo);
	print_message(data, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_count++;
	ft_sleep_ms(data->eat_time);
	put_down_forks(philo);
}

void philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_sleep_ms(data->sleep_time);
}

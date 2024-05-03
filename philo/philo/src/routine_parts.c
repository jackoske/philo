/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:51:33 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:12:02 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	if (check_anyone_dead(philo) || check_death(philo))
		return ;
	print_message(philo, "is thinking");
}


void	eat(t_philo *philo)
{
	if (check_anyone_dead(philo) || check_death(philo))
		return ;
	gettimeofday(&philo->last_eat, NULL);
	print_message(philo, "is eating");
	philo->eat_count++;
	ft_usleep_ms(philo->data->eat_time);
}



void	sleep_philo(t_philo *philo)
{
	if (check_anyone_dead(philo) || check_death(philo))
		return ;
	print_message(philo, "is sleeping");
	ft_usleep_ms(philo->data->sleep_time);
}

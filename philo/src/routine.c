/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:51:33 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/22 17:43:46 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

int	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_message(philo, "has taken a fork");
	}
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	print_message(philo, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_count++;
	ft_usleep_ms(philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->eat_mutex);
}

void	put_down_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
}

void	sleep_philo(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep_ms(philo->data->sleep_time);
}

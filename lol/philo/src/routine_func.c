/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:45 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 17:22:46 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_left_fork(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	check_time_to_starve(philo);
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d has taken a fork\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}

void	take_right_fork(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	check_time_to_starve(philo);
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d has taken a fork\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}

int	is_eating(t_philos *philo)
{
	philo->time_of_last_meal = get_time();
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is eating\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->data.eat_time, get_time(), NULL);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->data.meals_to_eat != 0)
	{
		philo->data.meals_to_eat--;
		if (philo->data.meals_to_eat == 0)
			return (0);
	}
	return (1);
}

void	is_sleeping(t_philos *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is sleeping\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->data.sleep_time, get_time(), philo);
}

void	is_thinking(t_philos *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is thinking\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}

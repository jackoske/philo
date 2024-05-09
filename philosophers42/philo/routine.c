/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:32:08 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:32:11 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo)
{
	while (1)
	{
		usleep(50);
		if (philo)
			check_time_till_starve(philo);
		if (((get_time() - exec_time)) >= time_to_sleep)
			break ;
	}
}

void	check_time_till_starve(t_philos *philo)
{
	if ((get_time() - philo->time_of_last_meal) >= philo->data.time_till_starve)
	{
		pthread_mutex_lock(philo->msg);
		pthread_mutex_lock(philo->die);
		*(philo->check_die) = 0;
		printf("%lldms philo %d died 💀🎃\n",
			(get_time() - philo->time), philo->id);
		pthread_mutex_unlock(philo->die);
	}
}

void	*routine_for_one(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	pthread_mutex_lock(philo->msg);
	pthread_mutex_lock(philo->left_fork);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(get_time() - philo->time), philo->id);
	ft_usleep(philo->data.time_till_starve, get_time(), NULL);
	pthread_mutex_lock(philo->die);
	*(philo->check_die) = 0;
	printf("%lldms philo %d died 💀🎃\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->die);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(30, get_time(), NULL);
	while (1)
	{
		check_time_till_starve(philo);
		take_left_fork(philo);
		take_right_fork(philo);
		if (!is_eating(philo))
			break ;
		is_sleeping(philo);
		is_thinking(philo);
	}
	pthread_mutex_lock(philo->meals);
	*(philo->count_meal) += 1;
	pthread_mutex_unlock(philo->meals);
	return (NULL);
}

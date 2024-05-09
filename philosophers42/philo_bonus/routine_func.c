/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:32:52 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:32:54 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_first_fork(t_philos *philosopher)
{
	sem_wait(philosopher->fork);
	check_time_till_starve(philosopher);
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is take a fork 🍴\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
}

void	take_second_fork(t_philos *philosopher)
{
	sem_wait(philosopher->fork);
	check_time_till_starve(philosopher);
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is take a fork 🍴\n", \
		(get_time() - philosopher->time), philosopher->id);
}

int	is_eating(t_philos *philosopher)
{
	printf("%lldms philo %d is eating 🍽️ 🍔\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
	philosopher->time_of_last_meal = get_time();
	ft_usleep(philosopher->data.eat_time, get_time(), NULL);
	sem_post(philosopher->fork);
	sem_post(philosopher->fork);
	if (philosopher->data.times_must_eat != 0)
	{
		philosopher->data.times_must_eat--;
		if (philosopher->data.times_must_eat == 0)
			return (0);
	}
	return (1);
}

void	is_sleeping(t_philos *philosopher)
{
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is sleeping 😴\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
	ft_usleep(philosopher->data.sleep_time, get_time(), philosopher);
	check_time_till_starve(philosopher);
}

void	is_thinking(t_philos *philosopher)
{
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is thinking 🤔 🤔\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
}

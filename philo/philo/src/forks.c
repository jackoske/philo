/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:23:41 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:08:43 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	pick_up_forks(t_philo *philo)
{
	if (check_anyone_dead(philo) || check_death(philo))
		return ;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (check_anyone_dead(philo) || check_death(philo))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return ;
		}
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->mutex);
		if (check_anyone_dead(philo) || check_death(philo))
		{
			pthread_mutex_unlock(&philo->right_fork->mutex);
			return ;
		}
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		if (check_anyone_dead(philo) || check_death(philo))
		{
			pthread_mutex_unlock(&philo->right_fork->mutex);
			return ;
		}
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (check_anyone_dead(philo) || check_death(philo))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return ;
		}
		print_message(philo, "has taken a fork");
	}
}
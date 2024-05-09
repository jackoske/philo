/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:35 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 19:09:40 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo)
{
	while (1)
	{
		usleep(50);
		if (philo)
			check_time_to_starve(philo);
		if (((get_time() - exec_time)) >= time_to_sleep)
			break ;
	}
}

void	ft_free(t_philos *philo_info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philo_info[i].meals);
	pthread_mutex_destroy(philo_info[i].write);
	pthread_mutex_destroy(philo_info[i].die);
	while (i < philo_info->data.n_philos)
	{
		pthread_mutex_destroy(philo_info[i].left_fork);
		free(philo_info[i].left_fork);
		i++;
	}
	free(philo_info->write);
	free(philo_info->die);
	free(philo_info->meals);
	free(philo_info->check_die);
	free(philo_info->count_meal);
	free(philo_info);
}

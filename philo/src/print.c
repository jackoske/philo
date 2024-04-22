/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:07:24 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/22 15:08:39 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

void	print_message(t_philo *philo, char *message)
{
	struct timeval	now;
	long			timestamp;

	gettimeofday(&now, NULL);
	timestamp = (now.tv_sec - philo->data->start_time.tv_sec) * 1000
		+ (now.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

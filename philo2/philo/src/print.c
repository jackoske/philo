/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:07:24 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 13:23:49 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

void	print_message(t_data *data, t_philo *philo, char *message)
{
	struct timeval	now;
	long			timestamp;

	gettimeofday(&now, NULL);
	timestamp = (now.tv_sec - data->start_time.tv_sec) * 1000
		+ (now.tv_usec - data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&data->write_mutex);
}

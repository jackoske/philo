/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:31:46 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 18:31:52 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	monitor_philosophers(t_philos *philos, int nbr_of_meal)
{
	while (1)
	{
		pthread_mutex_lock(philos->die);
		if (*(philos->check_die) == 0)
			break ;
		pthread_mutex_unlock(philos->die);
		pthread_mutex_lock(philos->meals);
		if (*(philos->count_meal) == nbr_of_meal)
			break ;
		pthread_mutex_unlock(philos->meals);
		usleep(50);
	}
}

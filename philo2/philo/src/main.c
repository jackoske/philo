/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:38:04 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 13:17:07 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		pthread_mutex_lock(&philo->left_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		pthread_mutex_lock(&philo->right_fork->mutex);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (create_threads(&data))
	{
		printf("Error: Failed to create philosopher threads\n");
		return (1);
	}
	join_threads(&data);
	// TODO: Wait for all threads to finish
	return (0);
}

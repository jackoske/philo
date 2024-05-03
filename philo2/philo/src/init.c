/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:31:47 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 12:35:01 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		printf("Error: Malloc failed\n");
		return (1);
	}
	i = -1;
	while (++i < data->philo_count)
	{
		(data->philos)[i].id = i + 1;
		(data->philos)[i].eat_count = 0;
		gettimeofday(&(data->philos)[i].last_eat, NULL);
		(data->philos)[i].left_fork = &data->forks[i];
		(data->philos)[i].right_fork = &data->forks[(i + 1) % data->philo_count];
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->eat_count = -1;
	if (argc == 6)
		data->eat_count = ft_atoi(argv[5]);
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1 || (argc == 6 && data->eat_count < 1))
		return (1);
	data->dead = 0;
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	data->forks = malloc(sizeof(t_fork) * data->philo_count);
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_init(&data->forks[i].mutex, NULL);
	gettimeofday(&data->start_time, NULL);
	return(init_philos(data));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:56:50 by zmoussam          #+#    #+#             */
/*   Updated: 2024/05/09 17:03:22 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free(t_philos *philo_info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philo_info[i].meals);
	pthread_mutex_destroy(philo_info[i].msg);
	pthread_mutex_destroy(philo_info[i].die);
	while (i < philo_info->data.n_philosophers)
	{
		pthread_mutex_destroy(philo_info[i].left_fork);
		free(philo_info[i].left_fork);
		i++;
	}
	free(philo_info->msg);
	free(philo_info->die);
	free(philo_info->meals);
	free(philo_info->check_die);
	free(philo_info->count_meal);
	free(philo_info);
}

void	wait_philosophers(t_philos *philos, int nbr_of_meal)
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

int	main(int argc, char **argv)
{
	t_data		args;
	t_philos	*philos;

	if (argc == 5 || argc == 6)
	{
		if (!validation(argv) || !(get_data_to_int(argv, &args)))
			return (0);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_philosophers);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		if (init_philo(philos, args) || start_philosophers(philos))
			return (0);
		wait_philosophers(philos, args.n_philosophers);
		ft_free(philos);
	}
	else
		printf("Need argument!!!\n");
}

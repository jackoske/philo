/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:31:47 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:42:01 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_philos *philo_info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philo_info[i].meals);
	pthread_mutex_destroy(philo_info[i].msg);
	pthread_mutex_destroy(philo_info[i].die);
	while (i < philo_info->data.n_philos)
	{
		pthread_mutex_destroy(philo_info[i].left_fork);
		i++;
	}
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
		if (!validate_input_arguments(argv) || !(convert_arguments_to_int_and_store(argv, &args)))
			return (0);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_philos);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		if (init_philo(philos, args) || start_philosophers(philos))
			return (0);
		wait_philosophers(philos, args.n_philos);
		ft_free(philos);
	}
	else
		printf("Need argument!!!\n");
}

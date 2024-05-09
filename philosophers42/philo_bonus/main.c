/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:32:39 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:32:41 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data		args;
	t_philos	*philos;

	if (argc == 5 || argc == 6)
	{
		validate_input_arguments(argv);
		convert_arguments_to_int_and_store(argv, &args);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_philos);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		init_sem(philos, args.n_philos);
		start_philo(args, philos);
		wait_philo(philos);
	}
	else
		printf("Need argument!!!\n");
	return (0);
}

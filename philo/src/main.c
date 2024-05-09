/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:51 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 18:51:01 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data		args;
	t_philos	*philos;

	if (argc == 5 || argc == 6)
	{
		if (!validation(argv) || !(get_data_to_int(argv, &args)))
			return (0);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_philos);
		if (philos == NULL)
			return (write(1, "Error: Failed to allocate memory!\n", 34));
		if (init_philo(philos, args) || start_philosophers(philos))
			return (0);
		monitor_philosophers(philos, args.n_philos);
		ft_free(philos);
	}
	else
		printf("Invalid Arguments\n");
}

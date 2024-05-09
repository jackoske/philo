/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:33:12 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:33:13 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	validate_input_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] > 32)
			{
				printf("Error: Invalid argument detected. Arguments must be digits.\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_empty_argumentsuments(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			printf("Error: Empty argument detected.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	convert_arguments_to_int_and_store(char **argv, t_data *philos_info)
{
	check_empty_arguments(argv);
	philos_info->n_philos = ft_atoi(argv[1]);
	if (philos_info->n_philos == 0)
		exit(EXIT_FAILURE);
	philos_info->time_till_starve = ft_atoi(argv[2]);
	philos_info->eat_time = ft_atoi(argv[3]);
	philos_info->sleep_time = ft_atoi(argv[4]);
	philos_info->times_must_eat = 0;
	if (argv[5] && argv[0] != '\0')
	{
		philos_info->times_must_eat = ft_atoi(argv[5]);
		if (philos_info->times_must_eat == 0)
			exit(EXIT_FAILURE);
	}
	if (philos_info->n_philos < 0 || philos_info->time_till_starve < 0
		|| philos_info->eat_time < 0 || philos_info->sleep_time < 0
		|| philos_info->times_must_eat < 0)
	{
		printf("Error: Invalid argument detected. Argument values must be non-negative.\n");
		exit(EXIT_FAILURE);
	}
}

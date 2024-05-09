/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:29 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 17:25:50 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	validation(char **argv)
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
				printf("error : arg invalide!!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write(1, "empty argument!!\n", 17);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_data_to_int(char **argv, t_data *philos_info)
{
	if (!check_empty_arg(argv))
		return (0);
	philos_info->n_philos = ft_atoi(argv[1]);
	if (philos_info->n_philos == 0)
		return (0);
	philos_info->time_to_starve = ft_atoi(argv[2]);
	philos_info->eat_time = ft_atoi(argv[3]);
	philos_info->sleep_time = ft_atoi(argv[4]);
	philos_info->meals_to_eat = 0;
	if (argv[5] && argv[0] != NULL)
	{
		philos_info->meals_to_eat = ft_atoi(argv[5]);
		if (philos_info->meals_to_eat == 0)
			return (0);
	}
	if (philos_info->n_philos < 0 || philos_info->time_to_starve < 0
		|| philos_info->eat_time < 0 || philos_info->sleep_time < 0
		|| philos_info->meals_to_eat < 0)
	{
		printf("error : arg invalide!! --> nombre long\n");
		return (0);
	}
	return (1);
}

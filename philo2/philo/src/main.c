/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:38:04 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 16:12:41 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

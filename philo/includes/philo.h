/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:22:56 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/20 12:05:49 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_data
{
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*forks;
	struct timeval	start;
}					t_data;

typedef struct s_philo
{
	int				id;
	t_fork			left_fork;
	t_fork			right_fork;
	int				eat_count;
	long			last_eat;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

int					ft_atoi(const char *str);
int					init_data(t_data *data, int argc, char **argv);
int					init_philos(t_data *data, t_philo **philos);
int					start_simulation(t_data *data, t_philo *philos);

#endif

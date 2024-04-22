/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:22:56 by Jskehan           #+#    #+#             */
/*   Updated: 2024/04/22 17:40:07 by Jskehan          ###   ########.fr       */
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
	t_fork	*forks;
	struct timeval	start_time;
}					t_data;

typedef struct s_philo
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				eat_count;
	struct timeval	last_eat;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

int					ft_atoi(const char *str);
int					init_data(t_data *data, int argc, char **argv);
int					init_philos(t_data *data, t_philo **philos);
void				think(t_philo *philo);
int					pick_up_forks(t_philo *philo);
void				eat(t_philo *philo);
void				put_down_forks(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				print_message(t_philo *philo, char *message);
void				ft_usleep_ms(int ms);
int					start_simulation(t_data *data, t_philo *philos);
int					check_if_philo_died(t_philo *philo);
int					check_death(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:22:56 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 16:52:52 by Jskehan          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				eat_count;
	struct timeval	last_eat;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				num_of_meals;
	int				current_index;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_t		monitor_thread;
	t_fork			*forks;
	struct timeval	start_time;
	t_philo			*philos;
}					t_data;

int					init_data(t_data *data, int argc, char **argv);
int					init_philos(t_data *data);

// Utils.c
void				print_message(t_data *data, char *message);
int					convert_time_to_ms(struct timeval time);
int					get_time_diff_ms(struct timeval start);
int					ft_atoi(const char *str);
void				ft_sleep_ms(int ms);

void				pick_up_forks(t_philo *philo);
void				put_down_forks(t_philo *philo);

void				think(t_data *data);
void				eat(t_data *data, t_philo *philo);
void				philo_sleep(t_data *data);

void				*monitor_routine(void *arg);
void				*philo_routine(void *arg);

int					create_threads(t_data *data);
void				join_threads(t_data *data);

#endif

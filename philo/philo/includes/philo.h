/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:22:56 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/03 18:15:32 by Jskehan          ###   ########.fr       */
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
	int				num_of_meals;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	struct timeval	start_time;
	pthread_t		monitor_thread;
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
int					convert_time_to_ms(struct timeval time);
int					ft_get_time_diff(struct timeval start, struct timeval end);
void				ft_usleep_ms(int ms);
int					ft_get_time(struct timeval start);

void				print_message(t_philo *philo, char *message);

int					init_data(t_data *data, int argc, char **argv);
int					init_philos(t_data *data, t_philo **philos);

void				think(t_philo *philo);
void				eat(t_philo *philo);
void				sleep_philo(t_philo *philo);

void				pick_up_forks(t_philo *philo);
void				put_down_forks(t_philo *philo);

void				*handle_one_philo(t_philo *philo);
void				*philo_routine(void *arg);

int					start_simulation(t_data *data, t_philo *philos);
void				*monitor_routine(void *arg);
int					check_death(t_philo *philo);
int					check_anyone_dead(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:23:08 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 18:31:05 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				n_philos;
	int				time_to_starve;
	int				eat_time;
	int				sleep_time;
	int				meals_to_eat;
}					t_data;

typedef struct s_philos
{
	int				id;
	int				*check_die;
	int				*count_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*die;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*write;
	long			time_of_last_meal;
	long			time;
	pthread_t		philo;
	t_data			data;
}					t_philos;

// Validation and Initialization Functions
void				init_mutex_write(t_philos *philosophers);
int					init_forks(t_philos *philos);
int					init_mutex(t_philos *philos);
int					init_philo(t_philos *philos, t_data philo_info);
int					validation(char **argv);
int					check_empty_arg(char **argv);
int					get_data_to_int(char **argv, t_data *philos_info);
int					start_philosophers(t_philos *philosophers);

// Routine Functions
void				*routine(void *arg);
void				*routine_for_one(void *arg);

// Utility Functions
long long			get_time(void);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_usleep(int time_to_sleep, long long exec_time,
						t_philos *philo);
void				ft_free(t_philos *philo_info);

// Philosopher Actions
void				check_time_to_starve(t_philos *philo);
void				take_fork(t_philos *philo, pthread_mutex_t *fork);
int					is_eating(t_philos *philo);
void				is_sleeping(t_philos *philo);
void				is_thinking(t_philos *philo);
int					if_there_is_one_philo(t_philos *philo);

// Wait Function
void				monitor_philosophers(t_philos *philos, int nbr_of_meal);

#endif

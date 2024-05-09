/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:31:56 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:42:38 by Jskehan          ###   ########.fr       */
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
	int				time_till_starve;
	int				eat_time;
	int				sleep_time;
	int				times_must_eat;
}					t_data;

typedef struct t_philosopher
{
	int				id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	msg;
	pthread_mutex_t	die;
	pthread_mutex_t	meals;
	int				*check_die;
	int				*count_meal;
	long			time_of_last_meal;
	pthread_t		philo;
	long			time;
	t_data			data;
}					t_philos;

int					validate_input_arguments(char **argv);
int					convert_arguments_to_int_and_store(char **argv,
						t_data *philos_info);
int					check_empty_arguments(char **argv);
int					start_philosophers(t_philos *philosophers);
int					init_philo(t_philos *philos, t_data philo_info);
int					init_forks(t_philos *philos);
int					init_mutex(t_philos *philos);
void				*routine(void *arg);
long long			get_time(void);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_usleep(int time_to_sleep, long long exec_time,
						t_philos *philo);
void				init_mutex_msg(t_philos *philosophers);
void				ft_free(t_philos *philo_info);
void				check_time_till_starve(t_philos *philo);
void				take_left_fork(t_philos *philo);
void				take_right_fork(t_philos *philo);
int					is_eating(t_philos *philo);
void				is_sleeping(t_philos *philo);
void				is_thinking(t_philos *philo);
int					if_there_is_one_philo(t_philos *philo);
void				*routine_for_one(void *arg);
void				wait_philosophers(t_philos *philos, int nbr_of_meal);

#endif

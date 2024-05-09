/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:32:47 by Jskehan           #+#    #+#             */
/*   Updated: 2024/05/09 15:32:48 by Jskehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <errno.h>
# include <fcntl.h> //For O_* constants
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h> // For mode constants
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define SEM_FORK "/forks"
# define SEM_PRINT_MSG "/print_msg"

typedef struct s_data
{
	int			n_philos;
	int			time_till_starve;
	int			eat_time;
	int			sleep_time;
	int			times_must_eat;
}				t_data;

typedef struct s_philos
{
	int			id;
	sem_t		*fork;
	sem_t		*print_msg;
	long long	time_of_last_meal;
	long long	time;
	t_data		data;
	int			fork_id;
}				t_philos;

void			validate_input_arguments(char **argv);
void			check_empty_arguments(char **argv);
void			convert_arguments_to_int_and_store(char **argv,
					t_data *philos_info);
void			ft_usleep(int time_to_sleep, long long exec_time,
					t_philos *philo);
void			check_time_till_starve(t_philos *philo);
long long		get_time(void);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			routine(t_philos *philosopher);
void			*start_philo(t_data args_info, t_philos *philosophers);
void			if_there_is_one_philo(t_philos *philo, t_data atgs);
void			init_sem(t_philos *philos, int nbr_of_philo);
void			wait_philo(t_philos *philo);
void			take_first_fork(t_philos *philosopher);
void			take_second_fork(t_philos *philosopher);
int				is_eating(t_philos *philosopher);
void			is_sleeping(t_philos *philosopher);
void			is_thinking(t_philos *philosopher);

#endif
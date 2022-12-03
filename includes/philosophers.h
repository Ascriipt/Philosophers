/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:45 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:51:10 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>

# define DEAD -1
# define ALIVE 0
# define SLEEPING 1
# define EATING 2

typedef pthread_mutex_t	t_mutex;

typedef struct s_args	t_arg;

typedef struct s_philo
{
	pthread_t			philo_id;
	int					id;
	int					laps;
	int					status;
	int					laps_done;
	int					last_meal;
	t_mutex				*pre_fork;
	t_mutex				id_fork;
	t_mutex				lock;
	t_arg				*args;
}				t_philo;

typedef struct s_args
{
	int		d_id;
	int		nop;
	int		nof;
	int		ttd;
	int		tte;
	int		tts;
	int		not;
	t_mutex	death;
	t_mutex	food;
	t_mutex	s_lock;
	t_philo	*philo;
}				t_arg;

/*------------------------check------------------------*/

int							check_arg(char **av);

/*------------------------inits------------------------*/

t_philo						*init_philos(int nop, t_arg *args);

void						init_val(int i, t_philo *philo);
void						*routine(void *argph);

/*------------------------time-------------------------*/

void						stopwatch(long unsigned int time_in_ms,
								t_philo *philo);

long unsigned int			get_time(void);

void						ft_usleep(long unsigned int time_in_ms,
								t_philo *philo);

/*-----------------------actions-----------------------*/

void						philo_print(t_philo *philo, const char *text);

void						thinking(t_philo *philo);
void						sleeping(t_philo *philo);
void						eating(t_philo *philo);

int							forking(t_philo *philo);
int							is_dead(t_philo *philo);

/*------------------------utils------------------------*/

int							one_philo(t_philo *philo);
long						ft_atoi(char *nptr);

void						create_threads(t_arg *args);
void						sepuku(t_philo *philo);

#endif
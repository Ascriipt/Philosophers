/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:45 by maparigi          #+#    #+#             */
/*   Updated: 2022/10/13 17:30:47 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHISOLOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>

# include "libft.h"

# define DEAD -1
# define ALIVE 0
# define SLEEPING 1
# define EATING 2

typedef pthread_mutex_t	t_mutex;

typedef struct s_args
{
	int	nop;
	int	nof;
	int	ttd;
	int	tte;
	int	tts;
	int	not;
}				t_arg;

typedef struct s_philo
{
	pthread_t			philo_id;
	int					id;
	int					laps;
	int					status;
	int					laps_done;
	t_mutex				*pre_fork;
	t_mutex				id_fork;
	t_mutex				lock;
	t_arg				args;
}				t_philo;

/*------------------------inits------------------------*/

t_philo						*init_philos(int nop, t_arg *args);

void						*routine(void *philo);

/*------------------------time-------------------------*/

void						stopwatch(long unsigned int time_in_ms,
								t_philo *philo);

long unsigned int			get_time(void);

/*-----------------------actions-----------------------*/

void						philo_print(t_philo *philo, const char *text);

void						thinking(t_philo *philo);
void						sleeping(t_philo *philo);
void						forking(t_philo *philo);
void						is_dead(t_philo *philo);
void						eating(t_philo *philo);

#endif
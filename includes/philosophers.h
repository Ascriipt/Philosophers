/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:45 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/27 17:24:23 by maparigi         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t			philo_id;
	int					id;
	int					laps;
	int					status;
	int					laps_done;
	t_mutex				id_fork;
	t_mutex				lock;
	t_mutex				aff;
}				t_philo;

typedef struct s_args
{
	int	nop;
	int	nof;
	int	ttd;
	int	tte;
	int	tts;
	int	not;
}				t_arg;

#endif
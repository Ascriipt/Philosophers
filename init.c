/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:17:13 by maparigi          #+#    #+#             */
/*   Updated: 2022/10/13 17:41:21 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	philo_print(t_philo *philo, const char *text)
{
	pthread_mutex_lock(&(philo->lock));
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(&(philo->lock));
		return ;
	}
	printf("%lu %d %s\n", get_time(), philo->id, text);
	pthread_mutex_unlock(&(philo->lock));
}

void	init_val(int i, t_philo *philo)
{
	philo->id = i;
	philo->laps = 0;
	philo->laps_done = 0;
	philo->status = ALIVE;
}

void	init_mutex(int nop, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < nop)
	{
		if (pthread_mutex_init(&(philos[i].id_fork), NULL) != 0)
			return ;
		if (pthread_mutex_init(&(philos[i].lock), NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < nop)
		philos[(i + 1) % nop].pre_fork = &philos[i].id_fork;
}

t_philo	*init_philos(int nop, t_arg *args)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * nop);
	if (!philos)
		return (NULL);
	init_mutex(nop, philos);
	while (++i < nop)
	{
		init_val(i, &philos[i]);
		philos[i].args = *args;
		if (pthread_create(&(philos[i].philo_id),
				NULL, routine, &philos[i]) != 0)
			return (NULL);
		if (pthread_join(philos[i].philo_id, NULL) != 0)
			return (NULL);
	}
	return (philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:17:13 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:09:02 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	philo_print(t_philo *philo, const char *text)
{
	pthread_mutex_lock(&(philo->args->s_lock));
	if (philo->status == DEAD || philo->args->d_id != -1)
	{
		pthread_mutex_unlock(&(philo->args->s_lock));
		return ;
	}
	printf("[%lu] {%d} %s\n", get_time(), philo->id + 1, text);
	pthread_mutex_unlock(&(philo->args->s_lock));
}

int	init_mutex_args(t_arg *args)
{
	if (pthread_mutex_init(&(args->s_lock), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(args->death), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(args->food), NULL) != 0)
		return (1);
	return (0);
}

void	init_val(int i, t_philo *philo)
{
	philo->id = i;
	philo->laps = 0;
	philo->laps_done = 0;
	philo->last_meal = get_time();
	philo->status = ALIVE;
}

int	init_mutex(int nop, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < nop)
	{
		if (pthread_mutex_init(&(philos[i].id_fork), NULL) != 0)
			return (1);
		if (pthread_mutex_init(&(philos[i].lock), NULL) != 0)
			return (1);
	}
	i = -1;
	while (++i < nop)
		philos[(i + 1) % nop].pre_fork = &philos[i].id_fork;
	return (0);
}

t_philo	*init_philos(int nop, t_arg *args)
{
	int		i;

	i = -1;
	args->philo = malloc(sizeof(t_philo) * nop);
	if (!args->philo)
		return (NULL);
	if (init_mutex_args(args))
		return (NULL);
	if (init_mutex(nop, args->philo) == 1)
		return (NULL);
	create_threads(args);
	i = -1;
	while (++i < nop)
	{
		if (pthread_join(args->philo[i].philo_id, NULL) != 0)
			return (NULL);
	}
	return (args->philo);
}

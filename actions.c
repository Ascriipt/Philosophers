/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/02 04:42:41 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	eating(t_philo *philo)
{
	int	i;

	i = 0;
	while (i == 0 && is_dead(philo))
	{
		if (forking(philo))
		{
			philo_print(philo, "is eating");
			ft_usleep(philo->args->tte, philo);
			philo->last_meal = get_time();
			philo->laps_done++;
			pthread_mutex_unlock(philo->pre_fork);
			pthread_mutex_unlock(&philo->id_fork);
			i++;
		}
	}
}

void	thinking(t_philo *philo)
{
	philo_print(philo, "is thinking");
}

int	forking(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->pre_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->id_fork);
		philo_print(philo, "has taken a fork");
		return (1);
	}
	else
	{
		pthread_mutex_lock(&philo->id_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->pre_fork);
		philo_print(philo, "has taken a fork");
		return (2);
	}
	return (0);
}

void	sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	stopwatch(philo->args->tts, philo);
}

int	is_dead(t_philo *philo)
{
	// printf("time since last meal: %lu\n", get_time() - philo->last_meal);
	if (get_time() - philo->last_meal >= (long unsigned int)philo->args->ttd)
	{
		if (philo->args->d_id != -1)
			return (0);
		sepuku(philo);
		philo->args->d_id = philo->id + 1;
		return (0);
	}
	if (philo->args->d_id != -1)
		return (0);
	return (1);
}

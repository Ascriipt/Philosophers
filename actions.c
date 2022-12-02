/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/02 02:01:50 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	eating(t_philo *philo)
{
	if (forking(philo) != 0)
	{
		philo_print(philo, "is eating");
		usleep(philo->args->tte * 1000);
		philo->last_meal = get_time();
		philo->laps_done++;
		pthread_mutex_unlock(philo->pre_fork);
		pthread_mutex_unlock(&philo->id_fork);
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
	printf("get_time() : %lu\n", get_time());
	printf("last meal : %d\n", philo->last_meal);
	printf("is dead ? : %ld\n", get_time() - philo->last_meal);
	printf("time to die : %d\n", philo->args->ttd);
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

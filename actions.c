/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/23 00:23:30 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	eating(t_philo *philo)
{
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
	philo_print(philo, "finished sleeping");
}

int	is_dead(t_philo *philo)
{
	if (get_time() - philo->last_meal >= (long unsigned int)philo->args->ttd)
	{
		sepuku(philo);
		return (0);
	}
	return (1);
}

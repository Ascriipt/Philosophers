/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/18 19:54:00 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

//void	eating(t_philo *philo)
//{
//}

//void	thinking(t_philo *philo)
//{
//}

int	forking(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->pre_fork);
		pthread_mutex_lock(&philo->id_fork);
		return (1);
	}
	else
	{
		pthread_mutex_lock(&philo->id_fork);
		pthread_mutex_lock(philo->pre_fork);
		return (2);
	}
	return (0);
}

void	sleeping(t_arg *argph)
{
	philo_print(argph->philo, "is sleeping");
	stopwatch(argph->tts, argph->philo);
	philo_print(argph->philo, "finished sleeping");
}

int	is_dead(t_arg *argph)
{
	if (get_time() - argph->philo->last_meal >= (long unsigned int)argph->ttd)
	{
		sepuku(argph->philo);
		pthread_mutex_unlock(&argph->philo->id_fork);
		return (0);
	}
	return (1);
}

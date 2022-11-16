/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/17 00:54:33 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

//void	eating(t_philo *philo)
//{
//}

//void	thinking(t_philo *philo)
//{
//}

void	forking(t_philo *philo)
{
	if (philo->id != 0)
	{
		pthread_mutex_lock(philo->pre_fork);
	}
	else
	{
		pthread_mutex_lock(&(philo->id_fork));
		if (pthread_mutex_lock(philo->pre_fork) == 0)
			return ;
		pthread_mutex_unlock(&(philo->id_fork));
		return ;
	}
}

void	sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	stopwatch(philo->args.tts, philo);
	philo_print(philo, "finished sleeping");
}

//void	is_dead(t_philo *philo)
//{
//}

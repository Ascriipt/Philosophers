/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:50 by maparigi          #+#    #+#             */
/*   Updated: 2022/10/13 17:55:11 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

//void	eating(t_philo *philo)
//{
//}

//void	thinking(t_philo *philo)
//{
//}

//void	forking(t_philo *philo)
//{
//}

void	sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	stopwatch(philo->args.tts, philo);
}

//void	is_dead(t_philo *philo)
//{
//}

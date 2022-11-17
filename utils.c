/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:27 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/17 02:22:13 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sepuku(t_philo *philo)
{
	//pthread_mutex_lock(&philo->lock);
	philo_print(philo, "has died");
	philo->status = DEAD;
	printf("yo");
	//pthread_mutex_unlock(&philo->lock);
}

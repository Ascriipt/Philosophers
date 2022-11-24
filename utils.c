/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:27 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/24 02:34:59 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	r;
	int	atoi;

	r = 1;
	atoi = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			r *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		atoi = atoi * 10 + *nptr - '0';
		nptr++;
	}
	return (atoi * r);
}

void	sepuku(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->s_lock));
	printf("[%lu] %d %s\n", get_time(), philo->id + 1, "has died");
	philo->status = DEAD;
	pthread_mutex_unlock(&(philo->args->s_lock));
}

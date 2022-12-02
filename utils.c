/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:27 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/02 05:23:09 by maparigi         ###   ########.fr       */
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

int	one_philo(t_philo *philo)
{
	printf("[%ld] {%d} has taken a fork\n", get_time(), philo->id);
	ft_usleep(philo->args->ttd, philo);
	return (0);
}

void	sepuku(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->s_lock));
	printf("[%lu] {%d} %s\n", get_time(), philo->id + 1, "died");
	philo->status = DEAD;
	pthread_mutex_unlock(&(philo->args->s_lock));
}

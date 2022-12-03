/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:27 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:36:43 by maparigi         ###   ########.fr       */
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
	printf("[%ld] {1} has taken a fork\n", get_time());
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

void	create_threads(t_arg *args)
{
	int	i;

	i = -1;
	while (++i < args->nop)
	{
		args->philo[i].args = args;
		init_val(i, &args->philo[i]);
		if (i % 2 == 0)
			if (pthread_create(&(args->philo[i].philo_id),
					NULL, routine, (void *)&args->philo[i]) != 0)
				return ;
	}
	usleep(10);
	i = -1;
	while (++i < args->nop)
	{
		if (i % 2 == 1)
			if (pthread_create(&(args->philo[i].philo_id),
					NULL, routine, (void *)&args->philo[i]) != 0)
				return ;
	}
}

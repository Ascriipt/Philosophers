/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:27 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:50:36 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi(char *nptr)
{
	long	i;
	long	s;
	long	sum;

	i = 0;
	s = 1;
	sum = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * s);
}

int	one_philo(t_philo *philo)
{
	printf("[%ld] {1} has taken a fork\n", get_time());
	usleep(philo->args->ttd * 1000);
	sepuku(philo);
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

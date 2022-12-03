/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:16:39 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:40:31 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long unsigned int	get_time(void)
{
	static long		init_time = 0;
	long int		time;
	struct timeval	tv;

	if (init_time == 0)
	{
		gettimeofday(&tv, NULL);
		init_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		time = 0;
	}
	else
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - init_time;
	}
	return (time);
}

void	ft_usleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time && is_dead(philo))
		usleep(100);
}

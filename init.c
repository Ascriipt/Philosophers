/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:17:13 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/29 19:12:48 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

t_philo	*init_philos(int nop)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * nop);
	if (!philos)
		return (NULL);
	while (++i < nop)
	{
		philos[i].id = i;
		philos[i].laps = 0;
		philos[i].laps_done = 0;
		philos[i].status = ALIVE;
		pthread_mutex_init(&(philos[i].aff), NULL);
		pthread_mutex_init(&(philos[i].lock), NULL);
		pthread_mutex_init(&(philos[i].id_fork), NULL);
		if (pthread_create(&(philos[i].philo_id), NULL, &threadtest, &i) != 0)
			return (NULL);
		if (pthread_join(philos[i].philo_id, NULL) != 0)
			return (NULL);
	}
	return (philos);
}

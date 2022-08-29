/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:17:13 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/29 18:28:38 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	init_philos(int nop, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < nop)
	{
		if (pthread_create(&(philos[i].philo_id), NULL, &threadtest, &i) != 0)
			return (1);
		if (pthread_join(philos[i].philo_id, NULL) != 0)
			return (2);
	}
	return (0);
}

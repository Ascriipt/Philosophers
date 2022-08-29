/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/29 21:00:01 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_destroyer(t_philo *philos, int nop)
{
	int	i;

	i = 0;
	while (++i < nop)
	{
		if (pthread_mutex_destroy(&(philos[i].id_fork)) != 0)
			return (1);
		if (pthread_mutex_destroy(&(philos[i].lock)) != 0)
			return (2);
	}
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*data;

	data = (t_philo *)philo;
	if (pthread_mutex_lock(data->next_fork) != 0)
		printf("%d is locked\n", data->id + 1);
	if (pthread_mutex_lock(&data->id_fork) != 0)
		return (NULL);
	else
		printf("%d is not locked\n", data->id);
	return (NULL);
}

void	att_val(int ac, char **av, t_arg *args)
{
	args->nop = ft_atoi(av[1]);
	args->nof = ft_atoi(av[1]);
	args->ttd = ft_atoi(av[2]);
	args->tte = ft_atoi(av[3]);
	args->tts = ft_atoi(av[4]);
	if (ac == 6)
		args->not = ft_atoi(av[5]);
	else
		args->not = -1;
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_arg		args;

	if (argc < 5 || argc > 6)
		return (1);
	att_val(argc, argv, &args);
	philos = init_philos(args.nop, &args);
	if (philos == NULL)
		return (2);
	mutex_destroyer(philos, args.nop);
	free(philos);
}

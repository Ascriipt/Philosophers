/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/11/17 02:31:24 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_forks(t_philo *philo)
{
	int	i;

	i = philo->args.nop;
	while (--i >= 0)
	{
		printf("fork of %d %p\n", i, (void *)&philo[i].id_fork);
		printf("fork of %d should be %p\n", i - 1, (void *)philo[i].pre_fork);
		printf("\n");
	}
}

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
	while (is_dead(philo) != -1)
		sleeping(philo);
	return (philo);
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
	{
		printf("Error : invalid number of arguments\n");
		return (1);
	}
	att_val(argc, argv, &args);
	philos = init_philos(args.nop, &args);
	if (philos == NULL)
		return (2);
	mutex_destroyer(philos, args.nop);
	free(philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/02 04:43:14 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_forks(t_arg *argph)
{
	int	i;

	i = argph->nop;
	while (--i >= 0)
	{
		printf("fork of %d %p\n", i, (void *)&argph->philo[i].id_fork);
		printf("fork of %d should be %p\n", i - 1,
			(void *)argph->philo[i].pre_fork);
		printf("\n");
	}
}

void	ft_usleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = get_time();
	// printf("time to eat %lu\n", time);
	while (get_time() - start < time && is_dead(philo))
		usleep(50);
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
	while (is_dead(philo))
	{
		if (!is_dead(philo))
			return (philo);
		eating(philo);
		if (!is_dead(philo))
			return (philo);
		sleeping(philo);
		if (!is_dead(philo))
			return (philo);
		thinking(philo);
	}
	return (philo);
}

void	att_val(int ac, char **av, t_arg *args)
{
	args->d_id = -1;
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
	t_arg		args;

	if (argc < 5 || argc > 6)
		return (printf("Error : invalid number of arguments\n"));
	att_val(argc, argv, &args);
	args.philo = init_philos(args.nop, &args);
	if (args.philo == NULL)
		return (printf("Error : malloc failed\n"));
	mutex_destroyer(args.philo, args.nop);
	free(args.philo);
}

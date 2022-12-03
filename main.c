/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:49:23 by maparigi         ###   ########.fr       */
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
	if (((t_philo *)philo)->args->nop == 1)
	{
		one_philo(philo);
		return (NULL);
	}
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
	if (check_arg(argv) == 0)
		return (printf("Error : invalid arguments\n"));
	att_val(argc, argv, &args);
	args.philo = init_philos(args.nop, &args);
	if (args.philo == NULL)
		return (printf("Error : malloc failed\n"));
	mutex_destroyer(args.philo, args.nop);
	free(args.philo);
}

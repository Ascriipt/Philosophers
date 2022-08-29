/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/29 19:03:51 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mutex	mutex_test;

void	print_philos(t_philo *philos, int nop)
{
	int	i;

	i = 0;
	while (++i < nop)
	{
		printf("is philo id %d\n", (philos[i]).id);
		printf("is philo status %d\n", (philos[i]).status);
		printf("is philo laps %d\n", (philos[i]).laps);
		printf("is philo laps done %d\n", (philos[i]).laps_done);
	}
}

void	*threadtest(void *id)
{
	pthread_mutex_lock(&mutex_test);
	printf("I am thread %d\n", *(int *)id);
	usleep(100000);
	pthread_mutex_unlock(&mutex_test);
	return (id);
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
	pthread_mutex_init(&mutex_test, NULL);
	philos = init_philos(args.nop);
	if (philos == NULL)
		return (2);
	pthread_mutex_destroy(&mutex_test);
	print_philos(philos, args.nop);
	free(philos);
}

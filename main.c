/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/29 18:15:20 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mutex	mutex_test;

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
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	att_val(argc, argv, &args);
	philos = malloc(sizeof(t_philo) * args.nop);
	if (!philos)
		return (2);
	pthread_mutex_init(&mutex_test, NULL);
	i = -1;
	while (++i < args.nop)
	{
		if (pthread_create(&(philos[i].philo_id), NULL, &threadtest, &i) != 0)
			return (3);
		if (pthread_join(philos[i].philo_id, NULL) != 0)
			return (4);
	}
	pthread_mutex_destroy(&mutex_test);
	free(philos);
}

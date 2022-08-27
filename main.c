/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/27 17:01:54 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*threadtest(void *id)
{
	printf("I am thread %d\n", *(int *)id);
	usleep(100000);
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
	pthread_t	*philos;
	t_arg		args;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	att_val(argc, argv, &args);
	philos = malloc(sizeof(philos) * args.nop);
	if (!philos)
		return (2);
	i = -1;
	while (++i < args.nop)
	{
		if (pthread_create(&philos[i], NULL, &threadtest, &i) != 0)
			return (3);
		if (pthread_join(philos[i], NULL) != 0)
			return (4);
	}
	free(philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:44:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/08/27 15:12:58 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	att_val(int ac, char **av, t_arg *args)
{
	args->nop = ft_atoi(av[1]);
	args->nof = ft_atoi(av[1]);
	args->ttd = ft_atoi(av[2]);
	args->tte = ft_atoi(av[3]);
	args->tts = ft_atoi(av[4]);
	if (ac == 6)
		args->not = ft_atoi(av[5]);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (argc < 5 || argc > 6)
		return (1);
	att_val(argc, argv, &args);
	printf("nop = %d", args.nop);
	printf("nof = %d", args.nof);
	printf("ttd = %d", args.ttd);
	printf("tte = %d", args.tte);
	printf("tts = %d", args.tts);
	printf("not = %d", args.not);
}

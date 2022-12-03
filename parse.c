/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:46:25 by maparigi          #+#    #+#             */
/*   Updated: 2022/12/03 01:46:51 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_digit(char *stack)
{
	int	i;

	i = -1;
	while (stack[i + 1] == '-' || stack[i + 1] == '+')
		i++;
	while (stack[++i])
		if (!(stack[i] >= '0' && stack[i] <= '9'))
			return (0);
	if (i >= 10 && (ft_atoi(stack) > 2147483647
			|| ft_atoi(stack) < -2147483648))
		return (0);
	return (1);
}

int	check_arg(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (is_digit(av[i]) == 0)
		{
			printf("Error : please input valid arguments\n");
			return (0);
		}
		if (ft_atoi(av[i]) < 0)
		{
			printf("Error : please only input positive arguments\n");
			return (0);
		}
	}
	return (1);
}

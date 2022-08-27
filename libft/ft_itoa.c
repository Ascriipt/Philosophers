/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:27:17 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/09 06:16:05 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *nbr, int n)
{
	int		i;
	int		j;
	char	swop;

	i = 0;
	j = n - 1;
	if (nbr[0] == '-')
		i++;
	while (i <= j)
	{
		swop = nbr[i];
		nbr[i] = nbr[j];
		nbr[j] = swop;
		i++;
		j--;
	}
	return (nbr);
}

static int	ft_get_size(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*dest;
	int			i;
	int			j;

	i = 0;
	nb = n;
	j = ft_get_size((long int)n);
	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[i++] = '-';
		nb = -nb;
	}
	while (i < j)
	{
		dest[i++] = nb % 10 + '0';
		nb /= 10;
	}
	dest[i] = '\0';
	return (ft_strrev(dest, j));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:25:39 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/10 03:27:13 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < size)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

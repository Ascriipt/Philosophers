/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:20:47 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/03 15:51:29 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;

	cpy = malloc(sizeof(const char) * ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	i = -1;
	while (s[++i])
		cpy[i] = ((char *)s)[i];
	cpy[i] = '\0';
	return (cpy);
}

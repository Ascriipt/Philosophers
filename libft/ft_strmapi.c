/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:26:27 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/04 17:27:46 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cpy;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	cpy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	while (s[++i])
		cpy[i] = f(i, s[i]);
	cpy[i] = '\0';
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:44:47 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/03 19:07:29 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		len = 0;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s[start++];
	dst[i] = '\0';
	return (dst);
}

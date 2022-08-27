/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:14:01 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/10 05:19:44 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nel;

	nel = (t_list *)malloc(sizeof(t_list) * 1);
	if (!nel)
		return (NULL);
	nel->content = content;
	nel->next = NULL;
	return (nel);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:01:28 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/10 23:24:59 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swop;

	if (!del || !lst || !*lst)
		return ;
	while (lst && (*lst))
	{
		swop = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = swop;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:38:46 by maparigi          #+#    #+#             */
/*   Updated: 2021/12/11 01:27:10 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;

	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	newlst = new;
	lst = lst->next;
	if (lst)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (!(new))
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, new);
			lst = lst->next;
		}
	}
	return (newlst);
}

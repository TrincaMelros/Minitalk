/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:36:05 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 13:54:29 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*nelem;

	if (!f || !lst)
		return (NULL);
	nlist = NULL;
	while (lst)
	{
		nelem = ft_lstnew(f(lst->content));
		if (!(nelem))
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, nelem);
		lst = lst->next;
	}
	return (nlist);
}

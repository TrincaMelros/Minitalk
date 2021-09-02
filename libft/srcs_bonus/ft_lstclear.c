/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:58:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 13:51:45 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nexter;

	if (!del)
		return ;
	while (*lst)
	{
		nexter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nexter;
	}
}

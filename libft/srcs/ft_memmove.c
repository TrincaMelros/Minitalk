/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:26:38 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:11:13 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*s1;
	char			*s2;
	unsigned int	i;

	if (!dst && !src)
		return (0);
	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (s2 < s1)
	{
		while (++i <= n)
		{
			s1[n - i] = s2[n - i];
		}
	}
	else
	{
		while (n-- > 0)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dst);
}

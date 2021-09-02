/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:00:29 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/23 14:34:06 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	if (!dst && !src)
		return (0);
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

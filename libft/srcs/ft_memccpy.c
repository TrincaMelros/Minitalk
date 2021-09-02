/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:14:54 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/23 14:33:21 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	s1 = (unsigned char *)d;
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:48:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/23 14:33:32 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned int	i;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		i++;
		s1++;
	}
	return (0);
}

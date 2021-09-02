/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 01:00:10 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 13:50:46 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long unsigned int	i;
	unsigned char		*sizzle;
	unsigned char		*bizzle;

	sizzle = (unsigned char *)s1;
	bizzle = (unsigned char *)s2;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			if (!sizzle[i] || !bizzle[i])
				return (sizzle[i] - bizzle[i]);
			if (sizzle[i] == bizzle[i])
				i++;
			else
				return (sizzle[i] - bizzle[i]);
		}
	}
	return (0);
}

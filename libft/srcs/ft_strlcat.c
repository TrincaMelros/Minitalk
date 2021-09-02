/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:25:48 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:17:56 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize < i)
	{
		while (src[j])
			j++;
		return (dstsize + j);
	}
	while (i < (dstsize - 1) && src[j] && dstsize > 0)
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

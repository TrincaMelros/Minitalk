/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:51:41 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/23 14:37:09 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	ptr = (char *)malloc(sizeof(*ptr) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

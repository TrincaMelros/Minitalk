/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:55:27 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 13:50:22 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	checker(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen((char *)s1);
	while (checker(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (checker(s1[end - 1], set))
		end--;
	ptr = ft_substr(s1, start, end - start);
	return (ptr);
}

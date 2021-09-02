/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:46:19 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/23 14:38:41 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	rlen;

	if (!s)
		return (0);
	rlen = ft_strlen(s);
	if (start >= rlen)
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	if (rlen < len)
		return (ft_strdup(s + start));
	str = (char *)malloc(len + 1);
	if (!(str))
		return (0);
	s1 = start;
	s2 = 0;
	while (s1 < rlen && s2 < len)
		str[s2++] = s[s1++];
	str[s2] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:01:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:11:46 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_words(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		arr_index;
	char	**array;

	if (!s)
		return (0);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!(array))
		return (0);
	array[count_words(s, c)] = 0;
	arr_index = 0;
	while (*s && *s == c)
		s++;
	j = 0;
	while (s[j])
	{
		i = j;
		while (s[j] && s[j] != c)
			j++;
		array[arr_index++] = ft_substr(s, i, j - i);
		while (s[j] && s[j] == c)
			j++;
	}
	return (array);
}

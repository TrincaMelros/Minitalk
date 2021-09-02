/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:46:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:08:14 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	counter(int n)
{
	int		i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	nbr = n;
	i = counter(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (0);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:37:14 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/02 13:37:11 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char *str)
{
	int	i;
	int	shifter;
	
	i = 0;
	printf("pid = %d\n", pid);
	while (str[i])
	{
		shifter = -1;
		while (++shifter < 8)
		{
			if (str[i] & 128 >> shifter)
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			usleep(5);
		}
		i++;
	}
}

int	main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Error: invalid arguments\n");
		printf("./client [PID] [MESSAGE]\n");
		return (0);
	}
	send_sig(ft_atoi(argv[1]), argv[2]);
	return (0);
}

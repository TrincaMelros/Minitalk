/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:37:14 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/03 12:01:47 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
**					# Final function #
**
**		This function sends 8 signals to the server, representing the NULL(0)
**		character, which lets the server know the transmission is finished.
*/

void	finish_transmission(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(30);
	}
}

/*
**					# Signal handling function #
**
**		This function handles the signals coming from the server program.
**
**		When the client receives a SIGUSR2 signal, it knows that the server
**		received the full string, closing the program.
*/

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("Message successfully sent ✅\n", 1);
		exit(0);
	}
}

/*
**					# Signal sending function#
**
**		This function converts each of the strings characters into
**		binary using bitwise operators, sending each bit as a signal
**		to the server. SIGUSR1 represents 0, while SIGUSR2 represents 1.
**
**		At the end it calls finish_transmission(), letting the server know
**		that the transmission is finished.
*/

void	send_sig(int pid, char *str)
{
	int	i;
	int	shifter;

	i = 0;
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
			usleep(30);
		}
		i++;
	}
	finish_transmission(pid);
}

/*
**					# Main client function #
**
**		sa_signals contains information on how the signals received from
**		the server will be interpreted.
**
**		A check is then made to make sure the correct number of inputs
**		are being given.
**
**		send_sig will then kick off the transmission of data to the server.
*/

int	main(int argc, char **argv)
{
	struct sigaction	sa_signals;

	sa_signals.sa_flags = SA_SIGINFO;
	sa_signals.sa_sigaction = sig_handler;
	if (argc != 3)
	{
		printf("Error: invalid arguments\n");
		printf("./client [PID] [MESSAGE]\n");
		return (0);
	}
	sigaction(SIGUSR2, &sa_signals, NULL);
	send_sig(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}

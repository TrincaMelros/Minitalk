/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:32:50 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/02 14:52:22 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	pid_printer(void)
{
	int	x;

	x = getpid();
	printf("PID is %d\n", x);
}

/*
**						# Signal handling function #
**
**		This function handles the signals coming from the client program.
**
**		SIGUSR1 represents the bit 0, while SIGUSR2 represents the bit 1.
**		This allows us to receive messages from the client bit by bit.
**
**
**
**
*/



void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 255;
	static int				shifter = 0;

	(void)context;
	(void)info;
	if (signum == SIGUSR1)
	{
		c ^= 128 >> shifter;
	}
	else if (signum == SIGUSR2)
	{
		c |= 128 >> shifter;
	}
	shifter++;
	if (shifter == 8)
	{
		printf("%c\n", c);
		shifter = 0;
		c = 255;
	}
}

/*
**						# Main server function #
**
**			sa_signal struct specifies how to handle a signal.
**
**			flag SA_SIGINFO specifies that when multiple signals are 
**			being received, they should be queued instead of blocked.
**
**			sa_sigaction states that sig_handler should be called when
**			a signal is received.
**
**			pid_printer retrieves the servers' pid and prints it.
**
**			the final loop keeps the server in an infinite loop, waiting
**			for signals from the client.
*/

int	main (void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	pid_printer();
	while (1)
		pause();
}

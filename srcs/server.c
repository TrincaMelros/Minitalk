/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:32:50 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/02 17:15:45 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
**						# Signal handling function #
**
**		This function handles the signals coming from the client program.
**
**		SIGUSR1 represents the bit 0, while SIGUSR2 represents the bit 1.
**		This allows us to receive messages from the client bit by bit.
**
**		info->si_pid allows us to retrieve the PID from the client, which
**		lets us send signals back to it.
**
**		Through bit wise operators we are able to transform receiving signals
**		into a char, which we then print one by one.
**
**		When the full string is received, we receive a NULL (0) char, which
**		means we can send a signal to the client to confirm the string
**		reached its destination.
*/

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 255;
	static int				shifter = 0;
	static int				pid = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 128 >> shifter;
	else if (signum == SIGUSR2)
		c |= 128 >> shifter;
	shifter++;
	if (shifter == 8)
	{
		write(1, &c, 1);
		shifter = 0;
		if (c == 0)
		{
			ft_putstr_fd("\n", 1);
			kill(pid, SIGUSR2);
		}
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
**			sigaction connects SIGUSR1 and 2 to the sig_handler function
**
**			ft_putnbr_fd writes to stdout the server's PID
**
**			the final loop keeps the server in an infinite loop, waiting
**			for signals from the client.
*/

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("The Pid is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}

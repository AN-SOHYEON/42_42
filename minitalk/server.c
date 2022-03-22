/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:42:17 by san               #+#    #+#             */
/*   Updated: 2022/02/25 10:52:20 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	reset(int *bit_length, int *message_char, int pid)
{
	*bit_length = 0;
	*message_char = 0;
	g_pid = pid;
}

void	ft_handler(int signum, siginfo_t *info, void *m)
{
	static int	bit_length;
	static int	message_char;
	char		itochar;

	(void)m;
	itochar = 0;
	if (g_pid != info->si_pid)
		reset(&bit_length, &message_char, info->si_pid);
	message_char = message_char << 1;
	if (signum == SIGUSR1)
		message_char = message_char + 1;
	else
		message_char = message_char + 0;
	bit_length++;
	if (bit_length == 8)
	{
		itochar = (char)message_char;
		write(1, &itochar, 1);
		reset(&bit_length, &message_char, info->si_pid);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	write(1, "SERVER_PID : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	s_sigaction.sa_sigaction = ft_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) != 0)
	{
		write(1, "SIGACTION ERROR\n", 15);
		exit(1);
	}
	if (sigaction(SIGUSR2, &s_sigaction, NULL) != 0)
	{
		write(1, "SIGACTION ERROR\n", 15);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}

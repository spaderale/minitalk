/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:11:42 by abroslav          #+#    #+#             */
/*   Updated: 2025/11/11 14:54:01 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	(void)context;
	if (sig == SIGUSR1)
		c = c | 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\nMensage received!\n", 19);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

void	setup_server_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	setup_server_signals();
	while (1)
		pause();
	return (0);
}

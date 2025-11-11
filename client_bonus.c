/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:59:49 by abroslav          #+#    #+#             */
/*   Updated: 2025/11/11 17:21:27 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_ack_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit--;
	}
}

void	setup_client_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
}

void	send_message(pid_t server_pid, char *msg)
{
	struct timeval	start;
	struct timeval	end;
	long			seconds;
	long			microseconds;
	long			total_time;
	int				i;

	gettimeofday(&start, NULL);
	i = 0;
	while (msg[i])
	{
		send_char(server_pid, msg[i]);
		i++;
	}
	send_char(server_pid, '\0');
	while (!g_ack_received)
		pause();

	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	total_time = seconds * 1000 + microseconds / 1000;

	ft_printf("Mensage delivered! Time: %u ms (%u bytes)\n", \
	(unsigned int)total_time, (unsigned int)i);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	msg = av[2];
	setup_client_signals();
	send_message(server_pid, msg);
	return (0);
}

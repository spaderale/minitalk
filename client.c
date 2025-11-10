/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:07:05 by abroslav          #+#    #+#             */
/*   Updated: 2025/11/10 02:22:01 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		printf("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	return (0);
}

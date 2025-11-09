#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while(bit >= 0)
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

	if(argc != 3)
		return (1);
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

/*void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		printf("Recebi SIGUSR1\n");
	else if (sig == SIGUSR2)
		printf("Recebi SIGUSR2\n");
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}*/

/*int	main(void)
{
	printf("Meu PID: %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}*/

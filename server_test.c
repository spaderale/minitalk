#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_bit(int sig)
{
	static unsigned char	c 	= 0;
	static int				bit	= 0;

	if (sig == SIGUSR1)
		c |= 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sa;

	write(1, "Server PID: ", 12);
	char pid_str[10];
	int len = 0;
	int pid = getpid();
	len = sprintf(pid_str, "%d\n", pid);
	write(1, pid_str, len);

	sa.sa_handler = &print_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

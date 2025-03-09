#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *arg)
{
	static char	c;
	static int	counter;

	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
	if (++counter == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		counter = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("pid = %d\n", getpid());
	while (1)
		pause();
}

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	g_arrived = 0;

void	send(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_arrived != 1)
			;
		g_arrived = 0;
		i--;
	}
}

void	handler(int sig)
{
	g_arrived = 1;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (0);
	signal(SIGUSR1, handler);
	pid = atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send(av[2][i], pid);
		i++;
	}
	send(av[2][i], pid);
	return (0);
}

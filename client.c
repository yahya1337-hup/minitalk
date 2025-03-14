/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:49:30 by yaboumei          #+#    #+#             */
/*   Updated: 2025/03/12 14:49:59 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_arrived = 0;

void	send(char c, int pid)
{
	int	i;
	int	err;

	i = 7;
	err = 0;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			err = kill(pid, SIGUSR1);
			if (err == -1)
				exit((ft_putstr_fd("you entered bad pid \n", 1), 1));
		}
		else
		{
			err = kill(pid, SIGUSR2);
			if (err == -1)
				exit((ft_putstr_fd("you entered bad pid \n", 1), 1));
		}
		while (g_arrived != 1)
			;
		g_arrived = 0;
		i--;
	}
}

void	handler(int sig)
{
	(void)sig;
	g_arrived = 1;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (0);
	if (!check_input(av[1]))
	{
		ft_putstr_fd("you entered bad pid \n", 1);
		return (0);
	}
	signal(SIGUSR1, handler);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send(av[2][i], pid);
		i++;
	}
	send(av[2][i], pid);
	ft_putstr_fd("The message is transferred\n", 1);
	return (0);
}

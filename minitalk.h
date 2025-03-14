/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:50:40 by yaboumei          #+#    #+#             */
/*   Updated: 2025/03/12 14:50:43 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
int		check_input(char *nbr);
void	ft_putnbr_fd(int n, int fd);

#endif

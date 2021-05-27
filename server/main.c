/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/27 22:57:36 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
//static	char g_global;
static char	g_char;

void	print_value(int val)
{
	static int	i = 0;

	i++;
	if (val == SIGUSR1)
	{
//ft_putchar_fd('a', 1);
		g_char = g_char | 1;
		g_char = g_char << 1;
	}
	else if (val == SIGUSR2)
	{
//ft_putchar_fd('b', 1);
		g_char = g_char ^ 0;
		g_char = g_char << 1;
	}
	/*for (int i = 0; i < sizeof(char); i++)
	{
		ft_putnbr_fd(g_char & 0x01, 1);
	}*/
	if (i == 8)
	{
		ft_putchar_fd(g_char, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_char = 0;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	//ft_putchar_fd('\n', 1);
	signal(SIGUSR1, print_value);
	signal(SIGUSR2, print_value);
	while (1)
	{
		pause();
	}
	return (0);
}

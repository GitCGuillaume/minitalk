/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/28 16:37:04 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

static unsigned char	g_c = 0;
static short	g_i = 0;

/*
 ** get 1 or 0 from signal, then just transform char c with
 ** tmp using exclusive OR /wiki/Bitwise_operation#XOR_2
*/
void	print_value(int val)
{
	unsigned char	tmp;

	tmp = 0;
	if (val == SIGUSR1)
	{
		tmp = tmp ^ 1;
		tmp = tmp << g_i;
		g_c = g_c ^ tmp;
		g_i++;
	}
	else if (val == SIGUSR2)
	{
		tmp = tmp & 0;
		tmp = tmp << g_i;
		g_c = g_c ^ tmp;
		g_i++;
	}
	if (g_i == 8)
	{
		ft_putchar_fd(g_c, 1);
		g_i = 0;
		g_c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, print_value);
	signal(SIGUSR2, print_value);
	while (1);
	return (0);
}

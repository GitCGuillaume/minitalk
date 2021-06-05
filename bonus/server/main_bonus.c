/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/06/05 20:28:45 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>


/*
 ** get 1 or 0 from signal, then just transform char c with
 ** tmp using exclusive OR /wiki/Bitwise_operation#XOR_2
*/

static t_values *g_values;

void	write_value(t_values **values, pid_t pid, int val)
{
	while (values && pid != g_values->pid)
		values = &(*values)->next;
	ft_putnbr_fd((*values)->pid, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	if (val == SIGUSR1)
	{
		(*values)->tmp = (*values)->tmp ^ 1;
		(*values)->tmp = (*values)->tmp << (*values)->g_i;
		(*values)->g_c = (*values)->g_c ^ (*values)->tmp;
		(*values)->g_i++;
	}
	else if (val == SIGUSR2)
	{
		(*values)->tmp = (*values)->tmp & 0;
		(*values)->tmp = (*values)->tmp << (*values)->g_i;
		(*values)->g_c = (*values)->g_c ^ (*values)->tmp;
		(*values)->g_i++;
	}
	if ((*values)->g_i == 8)
	{
		ft_putchar_fd((*values)->g_c, 1);
		(*values)->g_i = 0;
		(*values)->g_c = 0;
	}

}

void	print_value(int val)
{
	static short	g_i = 0;
	static unsigned char	g_c = 0;
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
	while (1)
	{
		signal(SIGUSR1, print_value);
		signal(SIGUSR2, print_value);
		pause();
	}
	return (0);
}

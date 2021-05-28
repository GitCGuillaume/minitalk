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

/*
 ** get 1 or 0 from signal, then just transform char c with
 ** tmp using exclusive OR /wiki/Bitwise_operation#XOR_2
*/
void	print_value(int val)
{
	static unsigned char	c = 0;
	unsigned char	tmp;
	static short	i = 0;

	tmp = 0;
	if (val == SIGUSR1)
	{
		tmp = tmp ^ 1;
		tmp = tmp << i;
		c = c ^ tmp;
		i++;
	}
	else if (val == SIGUSR2)
	{
		tmp = tmp & 0;
		tmp = tmp << i;
		c = c ^ tmp;
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
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

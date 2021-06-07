/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/06/07 22:52:00 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>


/*
 ** get 1 or 0 from signal, then just transform char c with
 ** tmp using exclusive OR /wiki/Bitwise_operation#XOR_2
*/

size_t	ft_strlen(unsigned char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}
/*
unsigned char	*fake_realloc(unsigned char *str, char c, size_t nb)
{
	unsigned char	*str_realloc;
	size_t	i;

	i = 0;
	str_realloc = NULL;
	if (ft_strlen(str) > nb)
	{
		if (str != NULL)
			free(str);
		exit(EXIT_FAILURE);
	}
	str_realloc = malloc((sizeof(unsigned char) * nb) + 1);
	if (str_realloc == NULL)
	{
		if (str)
			free(str);
		exit(EXIT_FAILURE);
	}
	if (str == NULL)
	{
		str_realloc[0] = c;
		str_realloc[1] = '\0';
	}
	else
	{
		while (str[i])
		{
			str_realloc[i] = str[i];
			i++;
		}
		str_realloc[i] = c;
		str_realloc[i + 1] = '\0';
		free(str);
	}
	return (str_realloc);
}
*/

void	print_value(int val)
{
	static unsigned char	buffer[2048];
	static unsigned int	i = 0;
	static unsigned int	nb = 0;
	unsigned char	tmp;

	tmp = 0;
	if (val == SIGUSR1)
	{
		tmp = tmp ^ 1;
		tmp = tmp << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	else if (val == SIGUSR2)
	{
		tmp = tmp & 0;
		tmp = tmp << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	if (i == 8)
	{
		if (buffer[nb] == '\0' || nb >= 2048)
		{
			nb = -1;
			ft_putstr_fd(buffer, 1);
			ft_bzero(buffer, ft_strlen(buffer));
		}
		nb = nb + 1;
		i = 0;
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

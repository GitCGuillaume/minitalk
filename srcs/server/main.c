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

void	end_print(unsigned char *buffer, unsigned int *i, int *nb, int *end)
{
	static unsigned char	*mem_buffer = NULL;
	unsigned char	*mem;

	if (*nb >= 10)
	{
		mem = ft_strjoin(mem_buffer, buffer);
		free(mem_buffer);
		mem_buffer = mem;
		//ft_memset(buffer, 0, ft_strlen(buffer));
		*nb = -1;
	}
	if (*end == 0)
	{
		if (*nb >= 0 && *nb < 10)
		{
			mem = ft_strjoin(mem_buffer, buffer);
			free(mem_buffer);
			mem_buffer = mem;
		//	ft_memset(buffer, 0,  ft_strlen(buffer));
		}
		write(1, mem_buffer, ft_strlen(mem_buffer));
		free(mem_buffer);
		mem_buffer = NULL;
		*nb = -1;
	}
	*end = 0;
	*nb = *nb + 1;
	*i = 0;
}
#include <stdio.h>
void	print_value(int val, siginfo_t *info, void *ucontext)
{
	static unsigned char	buffer[10];
	static unsigned int	i = 0;
	static int		nb = 0;
	static int		end = 0;
	unsigned char	tmp;

	(void)ucontext;
	tmp = 0;
	if (val == SIGUSR1)
	{
		tmp = (tmp ^ 1) << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
		end = tmp;
	}
	else if (val == SIGUSR2)
	{
		tmp = (tmp & 0) << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	if (i == 8)
		end_print(buffer, &i, &nb, &end);
	//printf("nb=%d\n i=%d\n", nb, i);
	if (nb == 0 && i == 0)
		ft_memset(buffer, 0,  ft_strlen(buffer));
	usleep(300);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;
	struct	sigaction s_sig_one;
	struct	sigaction s_sig_two;
	int	result;

	pid = getpid();
	s_sig_one.sa_sigaction = print_value;
	s_sig_one.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sig_one.sa_mask);
	s_sig_two.sa_sigaction = print_value;
	s_sig_two.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sig_two.sa_mask);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		result = sigaction(SIGUSR1, &s_sig_one, NULL);
		if (result < 0)
			exit(EXIT_FAILURE);
		result = sigaction(SIGUSR2, &s_sig_two, NULL);
		if (result < 0)
			result = sigaction(SIGUSR2, & s_sig_two, NULL);
		pause();
	}
	return (0);
}

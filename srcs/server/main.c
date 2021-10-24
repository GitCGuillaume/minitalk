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

unsigned char	*end_print(unsigned char *buffer, int *nb, int *end)
{
	static unsigned char	*mem_buffer = NULL;
	unsigned char	*mem;

	if (*nb == 4095)
	{
		mem = ft_strjoin(mem_buffer, buffer);
		free(mem_buffer);
		if (mem == NULL)
			return (NULL);
		mem_buffer = mem;
		ft_memset(buffer, 0, ft_strlen(buffer));
		*nb = -1;
	}
	if (*end == 0)
	{
		if (*nb >= 0 && *nb < 4095)
		{
			mem = ft_strjoin(mem_buffer, buffer);
			free(mem_buffer);
			if (mem == NULL)
				return (NULL);
			mem_buffer = mem;
			ft_memset(buffer, 0,  ft_strlen(buffer));
			*nb = -1;
		}
		write(1, mem_buffer, ft_strlen(mem_buffer));
		free(mem_buffer);
		mem_buffer = NULL;
	}
	*end = 0;
	*nb = *nb + 1;
	return (NULL);
}

void	print_value(int val, siginfo_t *info, void *ucontext)
{
	static unsigned char	buffer[4096];
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
	if (i >= sizeof(char *))
	{
		end_print(buffer, &nb, &end);
		i = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t	pid;
	struct	sigaction s_sig_one;
	struct	sigaction s_sig_two;
	int	result;

	pid = getpid();
	s_sig_one.sa_sigaction = print_value;
	sigemptyset(&s_sig_one.sa_mask);
	s_sig_one.sa_flags = SA_SIGINFO;
	s_sig_two.sa_sigaction = print_value;
	sigemptyset(&s_sig_two.sa_mask);
	s_sig_two.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	result = sigaction(SIGUSR1, &s_sig_one, NULL);
	if (result < 0)
		exit(EXIT_FAILURE);
	result = sigaction(SIGUSR2, &s_sig_two, NULL);
	if (result < 0)
		result = sigaction(SIGUSR2, & s_sig_two, NULL);
	while (1)
		pause();
	result = 0;
	return (0);
}

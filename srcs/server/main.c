/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 12:16:13 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

unsigned char	*g_mem_buffer;

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

void	end_print(unsigned char *buffer, int *nb, int *end)
{
	unsigned char			*mem;

	if (*nb == 4095)
	{
		mem = ft_strjoin(g_mem_buffer, buffer);
		free(g_mem_buffer);
		if (mem == NULL)
			exit(EXIT_FAILURE);
		g_mem_buffer = mem;
		ft_memset(buffer, 0, ft_strlen(buffer));
		*nb = -1;
	}
	if (*end == 0)
	{
		if (*nb >= 0 && *nb < 4095)
		{
			mem = ft_strjoin(g_mem_buffer, buffer);
			free(g_mem_buffer);
			if (mem == NULL)
				exit(EXIT_FAILURE);
			g_mem_buffer = mem;
			ft_memset(buffer, 0, ft_strlen(buffer));
			*nb = -1;
		}
		write(1, g_mem_buffer, ft_strlen(g_mem_buffer));
		free(g_mem_buffer);
		g_mem_buffer = NULL;
	}
	*end = 0;
	*nb = *nb + 1;
}

void	print_value(int val, siginfo_t *info, void *ucontext)
{
	static unsigned char	buffer[4096];
	static unsigned int		i = 0;
	static int				nb = 0;
	static int				end = 0;
	unsigned char			tmp;

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
	if (kill(info->si_pid, SIGUSR2) < 0)
		if (g_mem_buffer != NULL)
			free(g_mem_buffer);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sig_one;
	struct sigaction	s_sig_two;
	int					result;

	g_mem_buffer = NULL;
	pid = getpid();
	s_sig_one.sa_sigaction = print_value;
	if (sigemptyset(&s_sig_one.sa_mask) < 0)
		exit(0);
	s_sig_one.sa_flags = SA_SIGINFO;
	s_sig_two.sa_sigaction = print_value;
	if (sigemptyset(&s_sig_two.sa_mask) < 0)
		exit(0);
	s_sig_two.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	result = sigaction(SIGUSR1, &s_sig_one, NULL);
	if (result < 0)
	{
		if (g_mem_buffer != NULL)
			free(g_mem_buffer);
		exit(EXIT_FAILURE);
	}
	result = sigaction(SIGUSR2, &s_sig_two, NULL);
	if (result < 0)
	{
		if (g_mem_buffer != NULL)
			free(g_mem_buffer);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}

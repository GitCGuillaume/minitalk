/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:08:35 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/26 13:06:49 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

unsigned char	*g_mem_buffer;

void	alloc_print(unsigned char *buffer, unsigned int total, int *nb)
{
	unsigned char	*mem;

	mem = ft_strjoin(g_mem_buffer, buffer, total);
	free(g_mem_buffer);
	if (mem == NULL)
		exit(EXIT_FAILURE);
	g_mem_buffer = mem;
	ft_memset(buffer, 0, 4096);
	*nb = -1;
}

#include <stdio.h>
void	end_print(unsigned char *buffer, int *nb, int end)
{
	static unsigned int		total = 0;

	//total++;
	if (*nb == 4095)
	{
		total += 4096;
		alloc_print(buffer, total, nb);
	}
	if (end == 0)
	{
		if (*nb >= 0 && *nb < 4095)
		{
			total += *nb;
			alloc_print(buffer, total, nb);
		}
		write(1, g_mem_buffer, total);//ft_strlen(g_mem_buffer));
		free(g_mem_buffer);
		g_mem_buffer = NULL;
		total = 0;
	}
}

void	print_value(int val, siginfo_t *info, void *ucontext)
{
	static unsigned char	buffer[4096];
	static unsigned int		i = 0;
	static int				nb = 0;
	static int				end = 0;

	(void)ucontext;
	i = buffer_operator(val, nb, i, buffer);
	if (val == SIGUSR1)
		end = 1;
	if (i >= sizeof(char *))
	{
		end_print(buffer, &nb, end);
		i = 0;
		end = 0;
		nb++;
	}
	if (kill(info->si_pid, SIGUSR2) < 0)
	{
		if (g_mem_buffer != NULL)
			free(g_mem_buffer);
		g_mem_buffer = NULL;
	}
}

void	run_sigaction(struct sigaction *s_sig, int val)
{
	int	result;

	result = sigaction(val, s_sig, NULL);
	if (result < 0)
	{
		if (g_mem_buffer != NULL)
			free(g_mem_buffer);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sig_one;
	struct sigaction	s_sig_two;

	g_mem_buffer = NULL;
	pid = getpid();
	s_sig_one.sa_sigaction = print_value;
	if (sigemptyset(&s_sig_one.sa_mask) < 0)
		exit(0);
	if (sigaddset(&s_sig_one.sa_mask, SIGUSR1) < 0)
		exit(0);
	s_sig_one.sa_flags = SA_SIGINFO | SA_NODEFER;
	s_sig_two.sa_sigaction = print_value;
	if (sigemptyset(&s_sig_two.sa_mask) < 0)
		exit(0);
	if (sigaddset(&s_sig_two.sa_mask, SIGUSR2) < 0)
		exit(0);
	s_sig_two.sa_flags = SA_SIGINFO | SA_NODEFER;
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	run_sigaction(&s_sig_one, SIGUSR1);
	run_sigaction(&s_sig_two, SIGUSR2);
	while (1)
	{
		pause();
		usleep(500);
	}
	return (0);
}

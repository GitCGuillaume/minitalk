/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:09:17 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/26 16:06:56 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	check_args(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argv[2] == NULL)
	{
		ft_putstr_fd("No string parameter found.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	program_wait(int val)
{
	if (val == SIGUSR2)
	{
	//	write(1, "OK\n", 3);
		usleep(10);
	}
}

void	loop_message(char **argv, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (argv[2][i])
	{
		j = 0;
		while (j < (int) sizeof(char *))
		{
			if (argv[2][i] & 1)
			{
				if (kill(pid, SIGUSR1) < 0)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR2) < 0)
					exit(EXIT_FAILURE);
			}
			pause();
			j++;
			argv[2][i] = argv[2][i] >> 1;
		}
		i++;
	}
}

void	loop_end(int pid)
{
	int	i;

	i = 0;
	while ((int) sizeof(char *) > i)
	{
		if (kill(pid, SIGUSR2) < 0)
			exit(EXIT_FAILURE);
		pause();
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;
	int					i;
	int					pid;
	int					result;

	s_sig.sa_handler = program_wait;
	s_sig.sa_flags = SA_SIGINFO;
	if (sigemptyset(&s_sig.sa_mask) < 0)
		exit(EXIT_FAILURE);
	if (sigaddset(&s_sig.sa_mask, SIGUSR2) < 0)
		exit(EXIT_FAILURE);
	i = 0;
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	if (argv[2])
	{
		result = sigaction(SIGUSR2, &s_sig, NULL);
		if (result < 0)
			exit(EXIT_FAILURE);
		loop_message(argv, pid);
		loop_end(pid);
	}
	return (0);
}

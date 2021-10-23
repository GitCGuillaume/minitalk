/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:09:17 by gchopin           #+#    #+#             */
/*   Updated: 2021/06/07 22:49:04 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	check_args(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (argv[2] == NULL)
	{
		ft_putstr_fd("No string parameter found.\n", 2);
		exit(0);
	}

}

void	program_wait(int val)
{
	if (val == SIGUSR1)
		write(1, "OK\n", 3);
	usleep(300);
}

int	main(int argc, char **argv)
{
	struct sigaction s_sig;
	int	i;
	int	j;
	int	pid;
	int	result;

	s_sig.sa_handler = program_wait;
	s_sig.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sig.sa_mask);
	i = 0;
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	if (argv[2])
	{
		while (argv[2][i])
		{
			j = 0;
			while (j < (int)sizeof(char *))
			{
				if (argv[2][i] & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j++;
				argv[2][i] = argv[2][i] >> 1;
				result = sigaction(SIGUSR1, &s_sig, NULL);
				if (result < 0)
					exit(EXIT_FAILURE);
				pause();
			}
			i++;
		}
		i = 0;
		while (8 > i)
		{
			kill(pid, SIGUSR2);
			result = sigaction(SIGUSR1, &s_sig, NULL);
			if (result < 0)
				exit(EXIT_FAILURE);
			pause();
			i++;
		}
	}
	return (0);
}

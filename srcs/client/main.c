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

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	pid;

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
				usleep(5000);
				if (argv[2][i] & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j++;
				argv[2][i] = argv[2][i] >> 1;
			}
			i++;
		}
		j = 0;
		if (argv[2][i] == '\0')
		{
			i = 0;
			while (8 > i)
			{
				usleep(5000);
				kill(pid, SIGUSR2);
				i++;
			}
		}
	}
	return (0);
}

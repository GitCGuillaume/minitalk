/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:09:17 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/28 17:37:44 by gchopin          ###   ########.fr       */
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

	i = 0;
	check_args(argc, argv);
	if (argv[2])
	{
		while (argv[2][i])
		{
			j = 0;
			while (j < sizeof(char *))
			{
				if (argv[2][i] & 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				j++;
				argv[2][i] = argv[2][i] >> 1;
				usleep(20);
			}
			i++;
		}
	}
	return (0);
}

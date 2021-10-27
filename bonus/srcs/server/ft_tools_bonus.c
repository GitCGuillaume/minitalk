/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:59:01 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/27 17:11:42 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
 ** get 1 or 0 from signal, then just transform char c with
 ** tmp using exclusive OR
*/
int	buffer_operator(int val, int nb, unsigned int i, unsigned char *buffer)
{
	unsigned char	tmp;
	int				size;

	tmp = 0;
	size = (int) sizeof(char *) - 1;
	if (val == SIGUSR1)
	{
		tmp = (tmp ^ 1) << (i & size);
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	else if (val == SIGUSR2)
	{
		tmp = (tmp & 0) << (i & size);
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	return (i);
}

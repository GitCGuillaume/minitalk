/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:59:01 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/26 13:08:27 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
#include <stdio.h>
int	buffer_operator(int val, int nb, unsigned int i, unsigned char *buffer)
{
	unsigned char	tmp;

	tmp = 0;
	printf("buffer=%s\n i=%d\n", buffer, i);
	if (val == SIGUSR1)
	{
		tmp = (tmp ^ 1) << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	else if (val == SIGUSR2)
	{
		tmp = (tmp & 0) << i;
		buffer[nb] = buffer[nb] ^ tmp;
		i++;
	}
	return (i);
}

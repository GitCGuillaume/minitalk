/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:04:44 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/28 15:05:34 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*update_char;
	size_t			i;

	update_char = b;
	i = 0;
	while (len > i)
	{
		update_char[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

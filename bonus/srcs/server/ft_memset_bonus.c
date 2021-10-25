/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:02:54 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 15:56:36 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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

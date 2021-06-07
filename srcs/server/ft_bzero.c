/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:04:54 by gchopin           #+#    #+#             */
/*   Updated: 2021/06/07 21:26:15 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*assign_zero;
	size_t			i;

	i = 0;
	assign_zero = s;
	if (n > 0)
	{
		while (n > i)
		{
			assign_zero[i] = 0;
			i++;
		}
	}
}

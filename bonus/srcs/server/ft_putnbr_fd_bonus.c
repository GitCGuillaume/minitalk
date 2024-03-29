/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:14:07 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 15:57:04 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	ft_putnbr_fd(pid_t nbr, int fd)
{
	if (nbr == -2147483648)
		ft_putstr_fd((unsigned char *)"-2147483648", fd);
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(-nbr, fd);
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar_fd((int)nbr + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
}

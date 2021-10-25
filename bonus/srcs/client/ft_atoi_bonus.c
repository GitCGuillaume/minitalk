/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:33:14 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 15:59:24 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

static int	is_tab(char c)
{
	if (c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static int	is_jump(char c)
{
	if (c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

static int	is_other(char c)
{
	if (c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

pid_t	ft_atoi(const char *str)
{
	int		i;
	pid_t	result;
	pid_t	symbol;

	i = 0;
	result = 0;
	symbol = 1;
	while (is_tab(str[i]) || is_jump(str[i]) || is_other(str[i]))
		i++;
	if (str[i] == '-')
	{
		symbol = -symbol;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (symbol * result);
}

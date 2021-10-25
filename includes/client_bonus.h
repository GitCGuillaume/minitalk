/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:30:53 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 15:52:06 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

pid_t	ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);

#endif

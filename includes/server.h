/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:30:48 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 15:38:38 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2);
void			ft_putchar_fd(unsigned char c, int fd);
void			ft_putstr_fd(unsigned char *str, int fd);
void			ft_putnbr_fd(pid_t nbr, int fd);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(unsigned char *str);
int				buffer_operator(int val,
					int nb, unsigned int i, unsigned char *buffer);

#endif

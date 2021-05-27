#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(pid_t nbr, int fd);

#endif

#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_values
{
	int	pid;
	short	g_i;
	unsigned char	g_c;
	unsigned char	tmp;
	struct s_values *next;
} t_values;

void	ft_putchar_fd(unsigned char c, int fd);
void	ft_putstr_fd(unsigned char *str, int fd);
void	ft_putnbr_fd(pid_t nbr, int fd);
void	*ft_memset(void *b, int c, size_t len);
unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2);

#endif

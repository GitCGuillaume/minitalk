SERVER = ./srcs/server

CLIENT = ./srcs/client

SRCS = $(SERVER)/ft_putstr_fd.c $(SERVER)/ft_putnbr_fd.c $(CLIENT)/ft_atoi.c

OBJS = $(SRCS:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client

RM = rm -f

.c.o:
	clang -Wall -Wextra -Werror -Iincludes -c $< -o $(<:.c=.o)

all:	$(OBJS)
		clang -Wall -Wextra -Werror -Iincludes -o server $(OBJS) $(SERVER)/main.c
		clang -Wall -Wextra -Werror -Iincludes -o client $(OBJS) $(CLIENT)/main.c

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) server
	$(RM) client
	make clean

re: fclean all

.PHONY: all clean fclean re

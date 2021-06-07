SERVER = ./srcs/server

CLIENT = ./srcs/client

SRCS = $(SERVER)/ft_memset.c $(SERVER)/ft_bzero.c $(SERVER)/ft_putstr_fd.c $(SERVER)/ft_putnbr_fd.c $(CLIENT)/ft_atoi.c

MAIN_S = $(SERVER)/main.c

MAIN_C = $(CLIENT)/main.c

OBJS = $(SRCS:.c=.o)

OBJS_S = $(MAIN_S:.c=.o)

OBJS_C = $(MAIN_C:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client

RM = rm -f

CLANG = clang -Wall -Wextra -Werror

.c.o:
	$(CLANG) -Iincludes -c $< -o $(<:.c=.o)

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS) $(OBJS_S)
	$(CLANG) -Iincludes -o server $(OBJS) $(OBJS_S)

$(NAME_CLIENT): $(OBJS) $(OBJS_C)
	$(CLANG) -Iincludes -o client $(OBJS) $(OBJS_C)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)

fclean:
	$(RM) server
	$(RM) client
	$(RM) server_bonus
	$(RM) client_bonus
	make clean

re: fclean all

bonus: $(OBJS)
		clang -Wall -Wextra -Werror -Iincludes -o server_bonus $(OBJS) ./bonus/server/main_bonus.c
		clang -Wall -Wextra -Werror -Iincludes -o client_bonus $(OBJS) ./bonus/client/main_bonus.c

.PHONY: all clean fclean re bonus

SERVER = ./srcs/server

SERVER_B = ./bonus/srcs/server

CLIENT = ./srcs/client

CLIENT_B = ./bonus/srcs/client

SRCS = $(SERVER)/ft_tools.c $(SERVER)/ft_memset.c $(SERVER)/ft_putstr_fd.c $(SERVER)/ft_putnbr_fd.c $(CLIENT)/ft_atoi.c $(SERVER)/ft_strjoin.c

SRCS_B = $(SERVER_B)/ft_tools_bonus.c $(SERVER_B)/ft_memset_bonus.c $(SERVER_B)/ft_putstr_fd_bonus.c $(SERVER_B)/ft_putnbr_fd_bonus.c $(CLIENT_B)/ft_atoi_bonus.c $(SERVER_B)/ft_strjoin_bonus.c

MAIN_S = $(SERVER)/main.c

MAIN_SB = $(SERVER_B)/main_bonus.c

MAIN_C = $(CLIENT)/main.c

MAIN_CB = $(CLIENT_B)/main_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

OBJS_S = $(MAIN_S:.c=.o)

OBJS_SB = $(MAIN_SB:.c=.o)

OBJS_C = $(MAIN_C:.c=.o)

OBJS_CB = $(MAIN_CB:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_B = server_bonus

NAME_CLIENT_B = client_bonus

RM = rm -f

CLANG = clang -Wall -Wextra -Werror

.c.o:
	$(CLANG) -Iincludes -c $< -o $(<:.c=.o)

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS) $(OBJS_S)
	$(CLANG) -Iincludes -o $(NAME_SERVER) $(OBJS) $(OBJS_S)

$(NAME_CLIENT): $(OBJS) $(OBJS_C)
	$(CLANG) -Iincludes -o $(NAME_CLIENT) $(OBJS) $(OBJS_C)

$(NAME_SERVER_B): $(OBJS_B) $(OBJS_SB)
	$(CLANG) -Iincludes -o $(NAME_SERVER_B) $(OBJS_B) $(OBJS_SB)

$(NAME_CLIENT_B): $(OBJS_B) $(OBJS_CB)
	$(CLANG) -Iincludes -o $(NAME_CLIENT_B) $(OBJS_B) $(OBJS_CB)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)
	$(RM) $(OBJS_B)
	$(RM) $(OBJS_SB)
	$(RM) $(OBJS_CB)
fclean:
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_B)
	$(RM) $(NAME_CLIENT_B)
	make clean

re: fclean all

bonus:	$(NAME_SERVER_B) $(NAME_CLIENT_B)

.PHONY: all clean fclean re bonus

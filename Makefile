NAME = pipex
CC = gcc
HEADER = include/pipex.h
CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix src/, main.c utils.c)
SRCS_B = $(addprefix bonus/, main_bonus.c utils_bonus.c utils_bonus2.c)

LIB = libft/libft.a
INF = infile
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
 
all : tag $(INF) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

bonus: $(INF) $(LIB) $(OBJS_B)
	$(CC) $(OBJS_B) $(LIB) -o $(NAME)

$(LIB):
	make -C ./libft

$(INF):
	touch $@

clean:
	make clean -C ./libft
	rm -rf $(OBJS) $(OBJS_B)

fclean:
	make fclean -C ./libft
	rm -rf $(NAME) $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all bonus tag clean fclean re

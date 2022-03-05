NAME = minitalk
C_NAME = client
S_NAME = server
C_SRC = client.c
S_SRC	= server.c
BONUS_C_SRC = client_bonus.c
BONUS_S_SRC = server_bonus.c
LIB = ./libft/libft.a
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
BONUS_C_OBJ = $(BONUS_C_SRC:.c=.o)
BONUS_S_OBJ = $(BONUS_S_SRC:.c=.o)
HEAD = -I ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = -I ./includes/
RM = rm -f

$(NAME) : $(C_OBJ) $(S_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) -o $(C_NAME)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) -o $(S_NAME)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(C_OBJ) $(S_OBJ) $(BONUS_C_OBJ) $(BONUS_S_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

bonus : $(BONUS_C_OBJ) $(BONUS_S_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(BONUS_C_OBJ) $(LIB) -o $(C_NAME)
	$(CC) $(CFLAGS) $(BONUS_S_OBJ) $(LIB) -o $(S_NAME)

address	:	CFLAGS		+= -g -fsanitize=address
address	:	LIBFTTARGET	:= address
address	:	re

leak	:	CC			:= /usr/local/opt/llvm/bin/clang
leak	:	CFLAGS		+= -g -fsanitize=leak
leak	:	LIBFTTARGET	:= leak
leak	:	re

.PHONEY : all clean fclean re bonus address leak

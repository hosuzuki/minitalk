NAME = minitalk
C_NAME = client
S_NAME = server
C_SRC = srcs/client.c
S_SRC	= srcs/server.c
BONUS_C_SRC = srcs/client_bonus.c
BONUS_S_SRC = srcs/server_bonus.c
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
BONUS_C_OBJ = $(BONUS_C_SRC:.c=.o)
BONUS_S_OBJ = $(BONUS_S_SRC:.c=.o)
ifdef BONUS_ON
C_SRC = $(BONUS_C_SRC)
S_SRC = $(BONUS_S_SRC)
C_OBJ = $(BONUS_C_OBJ)
S_OBJ = $(BONUS_S_OBJ)
endif

LIB = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = -I ./includes
RM = rm -f

all : $(NAME)

$(NAME) : $(C_NAME) $(S_NAME)
	
$(C_NAME) : $(C_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) -o $(C_NAME)

$(S_NAME) : $(S_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) -o $(S_NAME)

$(LIB) :
	$(MAKE) -C ./libft

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(C_OBJ) $(S_OBJ) $(BONUS_C_OBJ) $(BONUS_S_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

bonus :
	$(MAKE) BONUS_ON=1

.PHONEY : all clean fclean re bonus

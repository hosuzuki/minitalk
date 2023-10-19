NAME	= minitalk
C_NAME	= client
S_NAME	= server
C_SRC	= srcs/client.c
S_SRC	= srcs/server.c
C_OBJ	= objs/client.o
S_OBJ	= objs/server.o
LIB		= ./ft_printf/libftprintf.a
OBJDIR	= objs/
SRCS	= $(C_SRC) $(S_SRC)
OBJS	= $(patsubst srcs/%.c, $(OBJDIR)%.o, $(SRCS))
DEPS	= $(OBJS:.o=.d)

# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP -g
HEAD	= -Iincludes/
RM		= rm -f

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS) $(C_NAME) $(S_NAME)
	@printf "$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(C_SRC) $(S_SRC))$(RC)\n"
	@printf "$(YE)=== Linked [$(CC)] ===\n--- $(C_NAME) $(S_NAME)$(RC)\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: srcs/%.c
	@$(CC) $(CFLAGS) $(HEAD) -c -o $@ $<
	
$(C_NAME) : $(C_OBJ) $(LIB)
	@printf "$(GR)=== Compiling $(C_NAME) ... [$(CC) $(CFLAGS) $(HEAD)] ===$(RC)\n"
	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) -o $(C_NAME)

$(S_NAME) : $(S_OBJ) $(LIB)
	@printf "$(GR)=== Compiling $(S_NAME) ... [$(CC) $(CFLAGS) $(HEAD)] ===$(RC)\n"
	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) -o $(S_NAME)

$(LIB) :
	$(MAKE) --no-print-directory -C ./ft_printf

clean :
	$(MAKE) --no-print-directory clean -C ./ft_printf
	$(RM) -r $(OBJDIR) 

fclean : clean
	$(MAKE) --no-print-directory fclean -C ./ft_printf
	$(RM) $(C_NAME) $(S_NAME)
	@printf "$(RE)=== Removed ===\n--- $(C_NAME), $(S_NAME)$(RC)\n"

re : fclean all

.PHONEY : all clean fclean re 

-include $(DEPS)
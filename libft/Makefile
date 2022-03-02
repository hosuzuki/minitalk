SHELL = /bin/sh

NAME = libft.a

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_putnbr_base.c \
	./ft_printf/ft_printf.c \
	./ft_printf/ft_analyze_fmt.c \
	./ft_printf/ft_turnon_flags.c \
	./ft_printf/ft_save_width_preci.c \
	./ft_printf/ft_print_address.c \
	./ft_printf/ft_print_char.c \
	./ft_printf/ft_print_decimal.c \
	./ft_printf/ft_print_unsigned.c \
	./ft_printf/ft_print_hex.c \
	./ft_printf/ft_print_str.c \
	./ft_printf/ft_print_flags.c \
	./ft_printf/ft_write_utils.c

OBJ = $(SRC:.c=.o)
HEAD = -I ./includes
CC = gcc
CFLAGS = -Wall -Werror -Wextra
ARC = ar rc
RAN = ranlib
RM = rm -f

$(NAME): $(OBJ)
	$(ARC) $(NAME) $?
	$(RAN) $(NAME)

all: $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

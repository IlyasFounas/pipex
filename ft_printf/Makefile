NAME    =   libftprintf.a
SRC     =   ft_printf.c ft_printf_utils.c
OBJ     =   $(SRC:.c=.o)
CFLAGS  =   -Wall -Wextra -Werror
CC      =   cc

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re

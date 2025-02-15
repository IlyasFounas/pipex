NAME    = pipex
SRC     = srcs/main.c \
		  srcs/manage_errors.c \
		  ft_printf/ft_printf.c \
		  ft_printf/ft_printf_utils.c 

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -I/usr/include -I../libft/includes -I includes
CC      = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT) $(OBJ) includes/pipex.h Makefile ft_printf/ft_printf.h
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c ft_printf/ft_printf.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all


all: $(NAME)

.PHONY: all clean fclean re


NAME    = pipex
SRC     = srcs/pipex.c \
		  srcs/pipex_utils.c \
		  srcs/pipex_execute.c \
		  srcs/pipex_check_errors.c 


MAKEFLAGS += --no-print-directory

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -Ilibft/includes -Iincludes
CC      = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT) $(OBJ) includes/pipex.h
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/pipex.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): force
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

all: $(NAME)

force:

.PHONY: all clean fclean re force


# Colors
RED = \e[31m
GRN = \e[32m
YLW = \e[33m
DEF = \e[0m

NAME = miniRT

SRC = src/main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra -g #-lm
CC = @cc

LIBFT = libft/libft.a
MLX42_DIR = MLX42
MLX42_A = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm

INCLUDES = -Iinclude -Ilibft -Iget_next_line -IMLX42/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX42_A)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX42_A) -o $(NAME) $(MLX42_FLAGS)

%.o: %.c
	@echo "$(YLW)Compiling object files...$(DEF)"
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YLW)Compiling Libft...$(DEF)"
	@make -C libft

$(MLX42_A):
	@mkdir -p MLX42/build
	@cd MLX42/build && cmake .. && make

clean:
	@echo "$(GRN)Removing object files...$(DEF)"
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@echo "$(GRN)Removing executable...$(DEF)"
	@rm -f $(NAME)
	@make -C libft fclean
	@rm -rf MLX42/build

re: fclean all

.PHONY: all clean fclean re

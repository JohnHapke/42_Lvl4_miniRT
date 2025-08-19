# Colors
RED = \033[31m
GRN = \033[32m
YLW = \033[33m
DEF = \033[0m

NAME = miniRT

SRC = src/main.c \
		src/parsing/error_handler.c \
		src/parsing/light_camera.c \
		src/parsing/parsing_handler.c \
		src/parsing/parsing_objects.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJDIR = obj/
OBJ= $(SRC:src/%.c=$(OBJDIR)%.o)

FLAGS = -Werror -Wall -Wextra -g #-lm
CC = @cc

LIBFT = libft/libft.a
MLX42_DIR = MLX42
MLX42_A = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm

INCLUDES = -Iinclude -Ilibft -Iget_next_line -IMLX42/include

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT) $(MLX42_A)
	@echo "$(YLW)MiniRT: Compiling executable...$(DEF)"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX42_A) -o $(NAME) $(MLX42_FLAGS)

$(OBJDIR):
	@echo "$(YLW)MiniRT: Creating $(OBJDIR) directory...$(DEF)"
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: src/%.c
	@echo "$(YLW)MiniRT: Compiling object files...$(DEF)"
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YLW)MiniRT: Compiling Libft...$(DEF)"
	@make -C libft bonus

$(MLX42_A):
	@echo "$(YLW)MiniRT: Compiling MLX42...$(DEF)"
	@mkdir -p MLX42/build
	@cd MLX42/build && cmake .. && make

clean:
	@echo "$(GRN)MiniRT: Removing object files...$(DEF)"
	@rm -f $(OBJ)
	@echo "$(GRN)MiniRT: Cleaning libft...$(DEF)"
	@make -C libft clean

fclean: clean
	@echo "$(GRN)MiniRT: Removing executable...$(DEF)"
	@rm -f $(NAME)
	@echo @echo "$(GRN)MiniRT: Removing object directory...$(DEF)"
	@rm -rf $(OBJDIR)
	@make -C libft fclean
	@rm -rf MLX42/build

re: fclean all

.PHONY: all clean fclean re

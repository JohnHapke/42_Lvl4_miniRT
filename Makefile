# Colors
RED = \033[31m
GRN = \033[32m
YLW = \033[33m
DEF = \033[0m

NAME = miniRT

SRC = src/main.c \
		src/parsing/error_handler.c \
		src/parsing/light_camera.c \
		src/parsing/handler.c \
		src/parsing/objects.c \
		src/parsing/syntax_controler.c \
		src/parsing/converter.c \
		src/parsing/utils.c \
		src/math_utils/vector_math.c \
		src/engine/ray_tracer.c \
		src/objects/sphere_intersection.c \
		src/objects/shading.c

GNL_SRC = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJDIR = obj/
OBJ= $(SRC:src/%.c=$(OBJDIR)%.o)
GNL_OBJ = $(GNL_SRC:get_next_line/%.c=$(OBJDIR)get_next_line/%.o)
ALL_OBJ = $(OBJ) $(GNL_OBJ)

FLAGS = -Werror -Wall -Wextra -g #-lm
CC = @cc

LIBFT = libft/libft.a
MLX42_DIR = MLX42
MLX42_A = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm

INCLUDES = -Iinclude -Ilibft -Iget_next_line -IMLX42/include

all: $(NAME)

$(NAME): $(OBJDIR) $(ALL_OBJ) $(LIBFT) $(MLX42_A)
	@echo "$(YLW)MiniRT: Compiling executable...$(DEF)"
	$(CC) $(FLAGS) $(ALL_OBJ) $(LIBFT) $(MLX42_A) -o $(NAME) $(MLX42_FLAGS)

$(OBJDIR):
	@echo "$(YLW)MiniRT: Creating $(OBJDIR) directory...$(DEF)"
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: src/%.c
	@echo "$(YLW)MiniRT: Compiling object files...$(DEF)"
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)get_next_line/%.o: get_next_line/%.c
	@echo "$(YLW)MiniRT: Compiling GNL object files...$(DEF)"
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
	@rm -rf $(ALL_OBJ)
	@make -C libft fclean
	@rm -rf MLX42/build
	@rm -rf obj/

re: fclean all

.PHONY: all clean fclean re

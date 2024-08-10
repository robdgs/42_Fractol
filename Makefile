NAME = fractol

CC = cc
CFLAGS = -Wextra -Werror -Wall -g -Imlx
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)

MINILIBX = ./minilibx-linux
MLX_A = -L$(MINILIBX) -lmlx
MLXFLAGS = -lX11 -lXext -lm

GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m

SRC =  main.c utils_one.c rendering.c init.c utils_two.c event_listeners.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@make all -C $(MINILIBX)
	@$(CC) $(CFLAGS) -I. $(OBJ) $(MLX_A) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)	FRACTOL COMPILED!$(RESET)"


RM = rm -f

clean:
	@$(RM) $(OBJ)
	@make clean -C $(MINILIBX)

fclean: clean
	@make clean -C $(MINILIBX)
	@$(RM) $(NAME)
	@echo "$(RED)	FRACTOL DESTROYED! $(RESET)"

re: fclean all
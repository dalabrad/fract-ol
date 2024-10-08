NAME = fractol

#LIBFT_DIR = ./libft
#LIBFT = $(LIBFT_DIR)/libft.a

#SRCS = $(wildcard src/pipex*.c)
#SRCS_BONUS = $(wildcard src_bonus/pipex*bonus.c)

MAIN = main.c

#OBJS = $(SRCS:.c=.o)

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a


CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
RM = rm -f

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m


$(NAME): $(LIBFT) $(PIPEX_LIB) $(MAIN)
	@echo "$(YELLOW)Compiling ./fractol executable...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(PIPEX_LIB) $(LIBFT)
	@echo "$(GREEN)./fractol executable created successfully.$(RESET)"



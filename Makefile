NAME = fractol

#LIBFT_DIR = ./libft
#LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard src/fractol*.c)

MAIN = main.c

OBJS = $(SRCS:.c=.o)

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


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@




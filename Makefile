NAME = fractol

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard src/fractol*.c)

MAIN = main.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a


CC = cc
CFLAGS = -Wall -Wextra -Werror
#FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
RM = rm -f

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m


$(NAME): $(OBJS) $(LIBFT)
	$(CC) -Iminilibx-linux $(MAIN) -o $(NAME) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:	
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

all: $(NAME)

re : fclean all	

.PHONY: all clean fclean re
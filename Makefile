RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = fdf

LIBFT = libft/libft.a

ifeq ($(shell uname), Linux)
	MLX_DIR = ./mlx_linux
	MLX_PATH = mlx_linux/libmlx.a
	MLX =  -L /usr/lib -lXext -lX11 -lm -lz 
	MLX_OBJ = -I/usr/include -Imlx_linux -O3
else
	MLX_DIR = ./mlx
	MLX_PATH = mlx/libmlx.a	
	MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit
	MLX_OBJ = -Imlx -c
endif
 
MLX_LIB = -L $(MLX_DIR) -lmlx

CC = cc

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = source/fdf.c source/create_window.c source/exit_error.c \
	   source/parsing.c source/get_next_line.c source/get_next_line_utils.c \
	   source/free_tab.c source/count_line.c source/atoi_hexa.c source/draw.c \
	   source/projection.c source/key_hook.c source/draw_line.c source/key_hook2.c \
	   source/key_hook3.c \

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	@make -C libft
	@printf "                                               \r"
	@echo "                 					"
	@echo "\033[0;34m 	███████╗ ██████╗   ███████╗     	"
	@echo "\033[0;34m	██╔════╝ ██╔══██╗  ██╔════╝		"
	@echo "\033[0;34m	█████╗   ██║  ██║  █████╗  		"
	@echo "\033[0;34m	██╔══╝   ██║  ██║  ██╔══╝  		"
	@echo "\033[0;34m	██║      ██████╔╝  ██║     		"
	@echo "\033[0;34m	╚═╝      ╚═════╝   ╚═╝  			"
	@echo "                 					"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g $(MLX_LIB) $(MLX) -o $(NAME)

%.o : %.c	
	@$(CC) -o $@ -c $<


fclean : clean
	@make fclean -C libft
	@$(RM) fdf

clean :
	@make clean -C libft
	@$(RM) source/*.o

re : fclean all 
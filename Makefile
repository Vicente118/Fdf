RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = fdf

LIBFT = libft/libft.a

# MLX = mlx/libmlx.a

CC = cc

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = source/fdf.c source/create_window.c source/exit_error.c \
	   source/parsing.c source/get_next_line.c source/get_next_line_utils.c \
	   source/free_tab.c source/place_points.c source/count_line.c\


OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@$(CC) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

%.o : %.c	
	@$(CC) -Imlx -o $@ -c $<

fclean : clean
	@make fclean -C libft
	@$(RM) fdf

clean :
	@make clean -C libft
	@$(RM) source/*.o

re : fclean all
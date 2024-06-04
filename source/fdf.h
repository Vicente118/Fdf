#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define HEIGHT 800
# define WIDTH 800

typedef struct s_mlx_data
{
    void    *mlx_connection;
    void    *mlx_window;
}           t_mlx_data;

typedef struct s_point
{
    int     x;
    int     y;
    int     z;
    char    *color;
}           t_point;

// WINDOW CREATION
t_mlx_data  *create_window(void);

// INPUT
int         handle_input(int keysym, t_mlx_data *data);

//PARSING
int         count_points(int fd);
t_point     *points_tab(int fd);

// ERROR MANAGEMENT
void        exit_error(void);
void        exit_malloc(void);

// GNL
char	    *get_next_line(int fd);

// FREE
void        free_tab(char **array);

 #endif 
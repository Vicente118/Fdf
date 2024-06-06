#ifndef FDF_H
# define FDF_H

//# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# ifdef LINUX
    # include <X11/keysym.h>
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

# define HEIGHT 1200
# define WIDTH 800

typedef struct s_mlx_data
{
    void    *mlx_connection;
    void    *mlx_window;
}           t_mlx_data;

typedef struct s_point
{
    int x;
    int y;
    int z;
    int x_proj;
    int y_proj;
    int color;
}           t_point;

// WINDOW CREATION
t_mlx_data  *create_window(void);

// INPUT
int         handle_input(int keysym, t_mlx_data *data);

//PARSING
int         count_points(int fd);
int         count_col(char **argv);
int         count_line(char **argv);

int         to_comma(char *string);
t_point     **init_points_tab(char **argv);
t_point     **fill_points_tab(char **argv);
size_t	    count_words(char const *s, char c);

//PLACE POINTS
void        place_points(t_point **points, t_mlx_data *data);

// ERROR MANAGEMENT
void        exit_error(void);
void        exit_malloc(void);

// GNL
char	    *get_next_line(int fd);

// FREE
void        free_tab(char **array);
void	    free_points_tab(t_point **array);
void	    free_tab_error(t_point **array, int i);

 #endif 
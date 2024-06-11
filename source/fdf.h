#ifndef FDF_H
# define FDF_H

//# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
#ifdef __linux__
    # include <X11/keysym.h>
    # include "../mlx_linux/mlx.h"
#endif
#ifdef __APPLE__
    # define XK_Escape 53
    # include "../mlx/mlx.h"
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define HEIGHT 1920
# define WIDTH 1080
// ALPHA WIDHT / HEIGHT
// FOV  1 / tan(teta / 2)
// lambda (Zfar / (Zfar - Znear)) - ((Zfar * Znear) / (Zfar - Znear))

typedef struct s_count
{
    int i;
    int j;
    int k;
}           t_count;

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
    int x_proj;
    int y_proj;
}           t_point;

typedef struct s_img
{
    void    *img_ptr;
    char    *img_pixels_ptr;
    int     bits_per_pixel;
    int     endian;
    int     size_line;
}           t_img;

typedef struct s_mlx_data
{
    void    *mlx_connection;
    void    *mlx_window;
    t_img   *img;
}           t_mlx_data;

// WINDOW CREATION
t_mlx_data  *create_window(void);

// INPUT
int         handle_input(int keysym, t_mlx_data *data);

//PARSING
int         count_points(int fd);
int         count_col(char **argv);
int         count_line(char **argv);
int         count_nb(char **array);
void        loop_fd(t_point ***points, char *line, int *k, char **argv);
t_point     **parse_fd(char **argv);
t_point     **init_points_tab(char **argv);
t_point     **fill_points_tab(char **argv);
size_t	    count_words(char const *s, char c);
int         atoi_hexa(char *str);

//PLACE POINTS
void        place_points(t_point **points, t_mlx_data *data);
void        draw_menu(t_mlx_data **data);
void        draw_background(t_mlx_data **data);
void        draw(t_mlx_data **data);

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
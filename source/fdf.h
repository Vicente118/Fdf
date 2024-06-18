/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:11 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/18 19:07:21 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  include <X11/keysym.h>
# endif
# ifdef __APPLE__
#  define XK_ESCAPE 53
#  define XK_O 31
#  define XK_I 34
#  define XK_UP 126
#  define XK_DOWN 125
#  define XK_LEFT 123
#  define XK_RIGHT 124
#  define XK_X 7
#  define XK_Y 16
#  define XK_Z 6
#  define XK_SPACE 49
#  define XK_D 2
#  define XK_A 0
#  define XK_X 7
#  define XK_N 45
#  define XK_M 46
#  include "../mlx/mlx.h"
# endif

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 1080
# define WIDTH 1920
// ALPHA WIDHT / HEIGHT
// FOV  1 / tan(teta / 2)
// lambda (Zfar / (Zfar - Znear)) - ((Zfar * Znear) / (Zfar - Znear))

typedef struct s_count
{
	int		i;
	int		j;
	int		k;
}			t_count;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	color;
	float	x_proj;
	float	y_proj;
	int		height;
	int		width;
	float	closest;
}			t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}			t_img;

typedef struct s_mlx_data
{
	void	*mlx_connection;
	void	*mlx_window;
	int		key_pressed[255];
	int		width;
	int		height;
	char	**argv;
	t_img	*img;
	t_point	*point;
}			t_mlx_data;

// WINDOW CREATION
t_mlx_data	*create_window(void);

// INPUT
void		init_key(t_mlx_data *data);
void		handle_input(int keysym, t_mlx_data *data);
int			handle_key(int keysym, t_mlx_data *data);
int			key_press(int keysym, t_mlx_data *data);
int			key_release(int keysym, t_mlx_data *data);

// PARSING
int			count_points(int fd);
int			count_col(char **argv);
int			count_line(char **argv);
int			count_nb(char **array);
void		loop_fd(t_point *points, char *line, int *k, char **argv);
t_point		*parse_fd(char **argv);
t_point		*init_points_tab(char **argv);
t_point		*fill_points_tab(char **argv);
size_t		count_words(char const *s, char c);
int			atoi_hexa(char *str);

// PLACE POINTS
void		place_points(t_point *points, t_mlx_data *data);
void		draw_menu(t_mlx_data *data, t_point *points);
void		draw_background(t_mlx_data *data);
void		draw(t_mlx_data *data, t_point *point);
void		text_menu(t_mlx_data *data);
float		zoom_factor(char **argv, t_mlx_data *data);
void		projection(t_point *points, t_mlx_data *data, char **argv);
void		draw_point(t_mlx_data *data, int x, int y, int color);
void		zoom_in(t_point *points, t_mlx_data *data);
void		zoom_out(t_point *points, t_mlx_data *data);
void		rotation_x(t_point *points, t_mlx_data *data, char **argv);
void		draw_line(t_mlx_data *data, int start_x, int start_y, int end_x,
				int end_y, int color0, int color1);
void		projection_paral(t_point *points, t_mlx_data *data, char **argv);

// ERROR MANAGEMENT
void		exit_error(void);
void		exit_malloc(void);

// GNL
char		*get_next_line(int fd);

// FREE
void		free_tab(char **array);
void		free_points_tab(t_point **array);
void		free_tab_error(t_point **array, int i);

#endif
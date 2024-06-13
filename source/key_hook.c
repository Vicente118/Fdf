#include "fdf.h"

void    handle_input(int keysym, t_mlx_data *data)
{
    write(1, "Window has been closed\n", 24);
    mlx_destroy_window(data->mlx_connection, data->mlx_window);
    // mlx_destroy_display(data->mlx_connection);
    free(data->mlx_connection);
    free(data);
    exit (1);
}

void		zoom_in(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].x_proj *= 1.1;
		(points)[i].y_proj *= 1.1;
		i++;
	}
	draw(data, points);
}

void	zoom_out(t_point *points, t_mlx_data *data)
{
	int i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].x_proj *= 0.9;
		(points)[i].y_proj *= 0.9;
		i++;
	}
	draw(data, points);
}

int		handle_key(int keysym, t_mlx_data *data /*, t_point ***points */)
{
	if (keysym == XK_i)
		zoom_in(data->point, data);
	else if (keysym == XK_o)
		zoom_out(data->point, data);
	else if (keysym == XK_Escape)
		handle_input(keysym, data);
	return(0);
}
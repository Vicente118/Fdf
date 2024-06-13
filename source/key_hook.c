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

void	translate_left(t_point *points, t_mlx_data *data)
{
	int	i;
	
	i = 0;
	while(points[i].x != -1)
	{
		(points)[i].x_proj -= 30;
		i++; 
	}
	draw(data, points);
}

void	translate_right(t_point *points, t_mlx_data *data)
{
	int	i;
	
	i = 0;
	while(points[i].x != -1)
	{
		(points)[i].x_proj += 30;
		i++; 
	}
	draw(data, points);
}

void	translate_up(t_point *points, t_mlx_data *data)
{
	int	i;
	
	i = 0;
	while(points[i].x != -1)
	{
		(points)[i].y_proj -= 30;
		i++; 
	}
	draw(data, points);
}

void	translate_down(t_point *points, t_mlx_data *data)
{
	int	i;
	
	i = 0;
	while(points[i].x != -1)
	{
		(points)[i].y_proj += 30;
		i++; 
	}
	draw(data, points);
}

// int	*rotation_x(t_point *points, t_mlx_data *data, char **argv)
// {
// 	int	i;
	
// 	i = 0;
// 	if (data->key_pressed[XK_x])
// 	{
// 		while(points[i].x != -1)
// 		{
// 			(points)[i].y = cos(0.0349066) * points[i].y - sin(0.0349066) * points[i].z;
// 			(points)[i].z = sin(0.0349066) * points[i].y + cos(0.0349066) * points[i].z;
// 			i++; 
// 		}
// 	}
// 	projection(data->point, argv);
// 	draw(data, points);
// 	return (0);
// }

int		handle_key(int keysym, t_mlx_data *data /*, t_point ***points */)
{
	if (keysym == XK_i)
		zoom_in(data->point, data);
	else if (keysym == XK_o)
		zoom_out(data->point, data);
	else if (keysym == XK_Escape)
		handle_input(keysym, data);
	else if (keysym == XK_Left)
		translate_left(data->point, data);
	else if (keysym == XK_Right)
		translate_right(data->point, data);
	else if (keysym == XK_Up)
		translate_up(data->point, data);
	else if (keysym == XK_Down)
		translate_down(data->point, data);
	return(0);
}
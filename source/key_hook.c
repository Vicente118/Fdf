/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/18 19:29:49 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_input(int keysym, t_mlx_data *data)
{
	write(1, "Window has been closed\n", 24);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data);
	exit(1);
}

void	zoom_in(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].x_proj *= 1.1;
		(points)[i].y_proj *= 1.1;
		(points)[i].x_proj -= 115;
		(points)[i].y_proj -= 40;
		i++;
	}
	draw(data, points);
}

void	zoom_out(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].x_proj *= 0.9;
		(points)[i].y_proj *= 0.9;
		(points)[i].x_proj += 115;
		(points)[i].y_proj += 40;
		i++;
	}
	draw(data, points);
}

void	translate_left(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (points[i].x != -1)
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
	while (points[i].x != -1)
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
	while (points[i].x != -1)
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
	while (points[i].x != -1)
	{
		(points)[i].y_proj += 30;
		i++;
	}
	draw(data, points);
}

void	decrease_altitude(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (points[i].x != -1)
	{
		if (points[i].z != 0)
			points[i].y_proj += points[i].z / 10;
		i++;
	}
	draw(data, points);
}

void	increase_altitude(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (points[i].x != -1)
	{
		if (points[i].z != 0)
			points[i].y_proj -= points[i].z / 10;
		i++;
	}
	draw(data, points);
}

void	rotation_x(t_point *points, t_mlx_data *data, char **argv)
{
	int	i;

	i = 0;
	while (points[i].x != -1)
	{
		(points)[i].x_proj = cos(0.0349066) * points[i].x_proj - sin(0.0349066)
			* points[i].y_proj;
		(points)[i].y_proj = sin(0.0349066) * points[i].x_proj + cos(0.0349066)
			* points[i].y_proj;
		i++;
	}
	draw(data, points);
}

int	handle_key(int keysym, t_mlx_data *data)
{
	if (keysym == XK_I)
		zoom_in(data->point, data);
	else if (keysym == XK_O)
		zoom_out(data->point, data);
	else if (keysym == XK_ESCAPE)
		handle_input(keysym, data);
	else if (keysym == XK_LEFT)
		translate_left(data->point, data);
	else if (keysym == XK_RIGHT)
		translate_right(data->point, data);
	else if (keysym == XK_UP)
		translate_up(data->point, data);
	else if (keysym == XK_DOWN)
		translate_down(data->point, data);
	else if (keysym == XK_D)
		decrease_altitude(data->point, data);
	else if (keysym == XK_A)
		increase_altitude(data->point, data);
	else if (keysym == XK_X)
		rotation_x(data->point, data, data->argv);
	else if (keysym == XK_M)
		projection_paral(data->point, data, data->argv);
	else if (keysym == XK_N)
		projection(data->point, data, data->argv);
	return (0);
}

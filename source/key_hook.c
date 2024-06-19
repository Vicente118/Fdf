/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/19 15:18:41 by vdarras          ###   ########.fr       */
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

int	handle_key(int keysym, t_mlx_data *data)
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
	else if (keysym == XK_d)
		decrease_altitude(data->point, data);
	else if (keysym == XK_q)
		increase_altitude(data->point, data);
	else if (keysym == XK_X)
		rotation_x(data->point, data, data->argv);
	else if (keysym == XK_m)
		projection_paral(data->point, data, data->argv);
	else if (keysym == XK_n)
		projection(data->point, data, data->argv);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:05 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/19 14:44:16 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

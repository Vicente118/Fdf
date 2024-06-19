/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:05 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/19 15:04:01 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_mlx_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * data->img->size_line) + (x * (data->img->bits_per_pixel
					/ 8));
		if (data->img->endian == 0)
		{
			data->img->img_pixels_ptr[pixel + 0] = (color & 0xFF);
			data->img->img_pixels_ptr[pixel + 1] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color >> 24) & 0xFF;
		}
		else
		{
			data->img->img_pixels_ptr[pixel + 0] = (color >> 24) & 0xFF;
			data->img->img_pixels_ptr[pixel + 1] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color & 0xFF);
		}
	}
}

void	draw_line(t_mlx_data *data, t_point start, t_point end, int color)
{
	start.x_proj = (int)start.x_proj;
	start.y_proj = (int)start.y_proj;
	end.x_proj = (int)end.x_proj;
	end.y_proj = (int)end.y_proj;
	data->dx = abs(end.x_proj - start.x_proj);
	data->dy = abs(end.y_proj - start.y_proj);
	data->sx = -1;
	data->sy = -1;
	if (start.x_proj < end.x_proj)
		data->sx = 1;
	if (start.y_proj < end.y_proj)
		data->sy = 1;
	data->err = data->dx - data->dy;
	while (1)
	{
		draw_point(data, start.x_proj, start.y_proj, color);
		if (start.x_proj == end.x_proj && start.y_proj == end.y_proj)
			break ;
		data->err2 = 2 * data->err;
		draw_line_condition(data, &start.x_proj, &start.y_proj);
	}
}

void	draw_line_condition(t_mlx_data *data, float *x, float *y)
{
	*x = (int)*x;
	*y = (int)*y;
	if (data->err2 > -data->dy)
	{
		data->err -= data->dy;
		*x += data->sx;
	}
	if (data->err2 < data->dx)
	{
		data->err += data->dx;
		*y += data->sy;
	}
}

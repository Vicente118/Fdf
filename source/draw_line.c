/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:05 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/18 19:14:46 by vdarras          ###   ########.fr       */
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

void	draw_line(t_mlx_data *data, int x0, int y0, int x1, int y1, int color0,
		int color1)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	float	ratio;
	int		e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		draw_point(data, x0, y0, color0);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

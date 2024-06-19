/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:32 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/19 15:12:20 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all(t_mlx_data *data, t_point *points)
{
	int	i;
	int	j;
	int	total;

	(data)->img->img_ptr = mlx_new_image((data)->mlx_connection, 1920, 1080);
	(data)->img->img_pixels_ptr = mlx_get_data_addr((data)->img->img_ptr,
			&((data)->img->bits_per_pixel), &((data)->img->size_line),
			&((data)->img->endian));
	first_loop(data);
	i = 0;
	total = data->height * data->width;
	while (i + 1 <= total)
	{
		draw_point(data, points[i].x_proj, points[i].y_proj, points[i].color);
		if ((i + 1) % data->width > 0)
			draw_line(data, points[i], points[i + 1], points[i].color);
		if ((i / data->width) < data->height - 1)
			draw_line(data, points[i], points[i + data->width],
				points[i].color);
		i++;
	}
	last_loop(data);
	mlx_put_image_to_window((data)->mlx_connection, (data)->mlx_window,
		(data)->img->img_ptr, 0, 0);
}

void	first_loop(t_mlx_data *data)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 1080)
	{
		j = 350;
		while (j < 1920)
		{
			pixel = (i * (data)->img->size_line) + (j * 4);
			((data)->img->img_pixels_ptr)[pixel + 0] = 0x16;
			((data)->img->img_pixels_ptr)[pixel + 1] = 0x16;
			((data)->img->img_pixels_ptr)[pixel + 2] = 0x15;
			((data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
			j++;
		}
		i++;
	}
}

void	last_loop(t_mlx_data *data)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 350)
		{
			pixel = (i * (data)->img->size_line) + (j * 4);
			((data)->img->img_pixels_ptr)[pixel + 0] = 0x2B;
			((data)->img->img_pixels_ptr)[pixel + 1] = 0x28;
			((data)->img->img_pixels_ptr)[pixel + 2] = 0x26;
			((data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
			j++;
		}
		i++;
	}
}

void	text_menu(t_mlx_data *data)
{
	int	color;

	color = 0xE7E5E5;
	mlx_string_put(data->mlx_connection, data->mlx_window, 115, 50, color,
		"--- FDF ---");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 130, color,
		"- Horizontal translation : arrows");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 170, color,
		"- Vertical translation : arrows");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 210, color,
		"- Zoom in : press I");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 250, color,
		"- Zoom out : press O");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 290, color,
		"- Rotation: press X");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 330, color,
		"- Increase altitude : press A");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 370, color,
		"- Decrease altitude : press D");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 410, color,
		"- Isometric projection : press N");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 450, color,
		"- Parallel projection : press M");
	mlx_string_put(data->mlx_connection, data->mlx_window, 12, 490, color,
		"- Press ESC to close the window");
}

void	draw(t_mlx_data *data, t_point *points)
{
	draw_all(data, points);
	text_menu(data);
}

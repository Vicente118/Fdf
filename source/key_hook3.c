/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:13 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/20 17:47:53 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_point *points, t_mlx_data *data)
{
	int		i;
	float	center_x;
	float	center_y;

	center_x = (WIDTH / 2.0) + 350;
	center_y = HEIGHT / 2.0;
	i = 0;
	while (points[i].x != -1)
	{
		data->translated_x = points[i].x_proj - center_x;
		data->translated_y = points[i].y_proj - center_y;
		data->rotated_x = cos(0.15708) * data->translated_x
			- sin(0.15708) * data->translated_y;
		data->rotated_y = sin(0.15708) * data->translated_x
			+ cos(0.15708) * data->translated_y;
		points[i].x_proj = data->rotated_x + center_x;
		points[i].y_proj = data->rotated_y + center_y;
		i++;
	}
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	draw(data, points);
}

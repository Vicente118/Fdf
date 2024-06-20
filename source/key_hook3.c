/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:13 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/20 12:33:05 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	draw(data, points);
}

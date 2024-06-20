/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:36 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/20 11:42:00 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	zoom_factor(char **argv, t_mlx_data *data)
{
	float	zoom;
	float	total;
	int		tot;

	total = data->height * data->width;
	if (total > 100000)
		zoom = 1.5;
	else if (total > 5000 && total < 100000)
		zoom = 2.5;
	else if (total < 5000 && total > 500)
		zoom = 5;
	else
		zoom = 20;
	return (zoom);
}

void	projection(t_point *points, t_mlx_data *data, char **argv)
{
	int		i;
	float	zoom;
	float	total;

	i = 0;
	zoom = zoom_factor(argv, data);
	total = data->height * data->width;
	while (points[i].x != -1)
	{
		(points)[i].x *= zoom;
		(points)[i].y *= zoom;
		(points)[i].z *= zoom;
		(points)[i].x_proj = ((points)[i].x - (points)[i].y) * (sqrt(3) / 2);
		(points)[i].y_proj = (((points)[i].x + (points)[i].y) / 2)
			- (points)[i].z;
		(points)[i].x_proj += 350 + (1920 - 350) / 2;
		if (total < 10000)
			(points)[i].y_proj += (1080 / 2) - 150;
		else
			(points)[i].y_proj += (1080 / 2) - 300;
		i++;
	}
}

void	projection_paral(t_point *points, t_mlx_data *data, char **argv)
{
	int		i;
	float	zoom;

	i = 0;
	zoom = zoom_factor(argv, data);
	while (points[i].x != -1)
	{
		(points)[i].x *= zoom;
		(points)[i].y *= zoom;
		(points)[i].x_proj = (points)[i].x * (sqrt(2) / 2);
		(points)[i].y_proj = (points)[i].y * (sqrt(2) / 2);
		(points)[i].x_proj += 350 + (1920 - 350) / 2;
		(points)[i].y_proj += (1080 / 2) - 300;
		i++;
	}
}

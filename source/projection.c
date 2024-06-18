/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:36 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/18 19:14:15 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_min(char **argv, t_mlx_data *data)
{
	int	lignes;
	int	col;

	lignes = data->height;
	col = data->width;
	if ((((1920 - 350) / col) / 2) < (1080 / lignes) / 2)
		return (((1920 - 350) / col) / 2);
	else
		return ((1080 / lignes) / 3);
}

float	zoom_factor(char **argv, t_mlx_data *data)
{
	float	zoom;
	int		tot;

	// tot = count_line(argv) * count_col(argv);
	zoom = 1.5;
	return (zoom);
}

void	projection(t_point *points, t_mlx_data *data, char **argv)
{
	int		i;
	float	zoom;

	i = 0;
	zoom = zoom_factor(argv, data);
	while (points[i].x != -1)
	{
		(points)[i].x *= zoom;
		(points)[i].y *= zoom;
		(points)[i].z *= zoom;
		(points)[i].x_proj = ((points)[i].x - (points)[i].y) * (sqrt(3) / 2);
		(points)[i].y_proj = (((points)[i].x + (points)[i].y) / 2)
			- (points)[i].z;
		(points)[i].x_proj += 350 + (1920 - 350) / 2;
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

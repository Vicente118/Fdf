/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:02 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/20 12:03:01 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	*create_window(void)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	data->img = malloc(sizeof(t_img));
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		exit_malloc();
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT,
			"Fdf");
	if (!data->mlx_window)
	{
		free(data->img);
		free(data);
		write(2, "Error while creating new window\n", 33);
		mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		mlx_destroy_display(data->mlx_connection);
		exit(1);
	}
	return (data);
}

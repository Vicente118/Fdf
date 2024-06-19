/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:09 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/19 15:26:43 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cross_event(t_mlx_data *data)
{
	write(1, "Window has been closed\n", 24);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->point);
	free(data->mlx_connection);
	free(data);
	free(data->img);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*data;
	t_point		*points;
	int			i;

	if (argc != 2)
	{
		ft_putstr_fd("Error bad number of arguments\n", 2);
		exit(1);
	}
	points = parse_fd(argv);
	data = create_window();
	data->point = points;
	data->argv = argv;
	data->width = count_col(argv);
	data->height = count_line(argv);
	if (data->width == -1 && data->height == 0)
		cross_event(data);
	projection(points, data, argv);
	draw(data, points);
	mlx_key_hook(data->mlx_window, &handle_key, data);
	mlx_hook(data->mlx_window, 17, 0, &cross_event, data);
	mlx_loop(data->mlx_connection);
}

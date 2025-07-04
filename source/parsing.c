/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:34 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/20 11:47:28 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*init_points_tab(char **argv)
{
	int		j;
	int		count;
	t_point	*points;
	int		col;

	col = count_col(argv);
	count = col * count_line(argv);
	if (count == -1)
	{
		write(2, "Error : nothing to read\n", 25);
		exit(1);
	}
	j = 0;
	points = malloc(sizeof(t_point) * (count + 1));
	if (!points)
		exit(1);
	points[count].x = -1;
	points[count].y = -1;
	return (points);
}

t_point	*parse_fd(char **argv)
{
	t_point	*points;
	char	**array;
	int		k;
	char	*line;
	int		fd;

	points = init_points_tab(argv);
	k = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	while (line != NULL)
	{
		loop_fd(points, line, &k, argv);
		free(line);
		line = get_next_line(fd);
	}
	return (points);
}

void	loop_fd(t_point *points, char *line, int *k, char **argv)
{
	char	**array;
	char	*temp;
	int		i;
	int		count;

	array = ft_split(line, ' ');
	if (!array)
		exit_malloc();
	count = count_nb(array);
	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], "\n", 1) == 0)
			break ;
		points[*k].x = i;
		points[*k].y = *k / count;
		points[*k].z = ft_atoi(array[i]);
		if (ft_strchr(array[i], ',') == NULL)
			points[*k].color = atoi_hexa("F7F3E3");
		else
			points[*k].color = atoi_hexa(ft_strchr(array[i], 'x') + 1);
		i++;
		*k = *k + 1;
	}
	free_tab(array);
}

int	count_nb(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], "\n", 1) == 0)
			break ;
		i++;
	}
	return (i);
}

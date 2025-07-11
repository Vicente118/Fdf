/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:00 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/18 19:08:11 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_col(char **argv)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit_error();
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	count = count_words(line, ' ');
	if (*(ft_strrchr(line, ' ') + 1) == '\n')
		count--;
	free(line);
	close(fd);
	return (count);
}

int	count_line(char **argv)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

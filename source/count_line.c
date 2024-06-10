#include "fdf.h"

int	count_col(char **argv)
{
	int	count;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY, 0777);
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	count = count_words(line, ' ');
	if (*(ft_strrchr(line, ' ') + 1) == '\n')
		count--;
	close (fd);
	return (count);
}

int	count_line(char **argv)
{
	int		count;
	char	*line;
	int		fd;
	
	count = 0;
    fd = open(argv[1], O_RDONLY, 0777);
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
#include "fdf.h"

int count_points(int fd)
{
    int     x_points;
    int     y_points;
    char    **grid;
    char    *line;
    
    x_points = 0;
    line = get_next_line(fd);
    y_points = 0;
    grid = ft_split(line, ' ');
    free(line);
    if(!grid)
        return(-1);
    while (grid[x_points])
        x_points++;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            free(line);
        y_points++;
    }
    return (free_tab(grid), y_points * x_points);
}

t_point **points_tab(int fd)
{
    int     i;
    int     j;
    int     k;
    int     count;
    char    *line;
    char    **array;
    t_point **points;

    count = count_points(fd);
    j = 0;
    *points = malloc(sizeof(t_point) * count);
    if (count == -1)
    {
        write(2, "Error : nothing to read\n", 25);
        exit(1);
    }
                            // PARSER MAP

    return(points);
}

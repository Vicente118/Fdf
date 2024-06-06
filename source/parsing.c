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

t_point **init_points_tab(int fd)
{
    int     j;
    int     count;
    t_point **points;

    count = count_points(fd);
    if (count == -1)
    {
        write(2, "Error : nothing to read\n", 25);
        exit(1);
    }
    j = 0;
    points = malloc(sizeof(t_point *) * (count + 1));
    if (!points)
        exit(1);
    while (j < count)
    {
        points[j] = malloc(sizeof(t_point));
        if (!points[j])
            free_tab_error(points, j);
        j++;
    }
    points[j] = NULL;   
    return(points);
}

t_point **fill_points_tab(int fd, char **argv)
{
    t_point **points;
    char    **array;
    char    **temp;
    char    *line;
    int     i;
    int     j;
    int     k;

    points = init_points_tab(fd);
    j = 0;
    k = 0;
    close(fd);
    fd = open(argv[1], O_RDONLY, 0777);
    if (fd == -1)
        exit_error();
    while (1)
    {
        i = 0;
        line = get_next_line(fd);
        if (!line)
            break;
        temp = ft_split(line, ' ');
        array = temp;
        free(line);
        if (!array)
            exit(1);
        while (array[i])
        {
            if (ft_strchr(array[i], ',') == NULL)
            {
                points[j]->x = i;
                points[j]->y = k;
                points[j]->z = ft_atoi(array[i]);
                points[j]->color = "0xffffff"; 
            }
            else
            {
                points[j]->x = i;
                points[j]->y = k;
                points[j]->z = ft_atoi(array[i]);
                if (ft_strchr(array[i], '\n') == NULL)
                {
                    points[j]->color = ft_strchr(array[i], ',') + 1;
                }
                else
                    points[j]->color = ft_strtrim(ft_strchr(array[i], ',') + 1, "\n");  
            }
            j++;
            i++;
        }
        free_tab(temp);
        k++;
    }
    close(fd);
    return (points);
}

int to_comma(char *string)
{
    char    new_str;
    int     i;

    i = 0;
    while (string[i] != ',')
        i++;
    return (i);
}
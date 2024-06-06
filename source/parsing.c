#include "fdf.h"

t_point **init_points_tab(char **argv)
{
    int     j;
    int     count;
    t_point **points;

    count = count_col(argv) * count_line(argv);
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

t_point **fill_points_tab(char **argv)
{
    t_point **points;
    char    **array;
    char    **temp;
    char    *line;
    int     i;
    int     j;
    int     fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_error();
    points = init_points_tab(argv);
    
    // while (1)
    // {
    //     i = 0;
    //     line = get_next_line(fd);
    //     if (!line)
    //         break;
    //     temp = ft_split(line, ' ');
    //     array = temp;
    //     free(line);
    //     if (!array)
    //         exit(1);
    //     while (array[i])
    //     {
    //         if (ft_strchr(array[i], ',') == NULL)
    //         {
    //             points[j]->x = i;
    //             points[j]->y = k;
    //             points[j]->z = ft_atoi(array[i]);
    //             points[j]->color = 0xffffff; 
    //         }
    //         else
    //         {
    //             points[j]->x = i;
    //             points[j]->y = k;
    //             points[j]->z = ft_atoi(array[i]);
    //             if (ft_strchr(array[i], '\n') == NULL)
    //             {
    //                 points[j]->color = ;
    //            }    
    //             else
    //                 points[j]->color = ;
    //         }
    //         j++;
    //         i++;
    //     }
    //     free_tab(temp);
    //     k++;
    // }
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
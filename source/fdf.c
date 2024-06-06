#include "fdf.h"

int    handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        write(1, "Window has been closed\n", 24);
        mlx_destroy_window(data->mlx_connection, data->mlx_window);
        mlx_destroy_display(data->mlx_connection);
        free(data->mlx_connection);
        free(data);
        exit (1);
    }
    printf("The %c key has been pressed\n", keysym - 32);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    int count;
    t_mlx_data  *data;
    t_point    **points;
    int i = 0;

    fd = open(argv[1], O_RDONLY, 0777);
    if (fd == -1)
        exit_error();
    points = fill_points_tab(fd, argv);
    while (points[i])
    {
        printf("%s\n", points[i]->color);
        i++;
    }
    close(fd);

    data = create_window();
    mlx_key_hook(data->mlx_window, handle_input, data);
    place_points(points, data);
    free_points_tab(points);
    mlx_loop(data->mlx_connection);
}


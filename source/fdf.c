#include "fdf.h"

int    handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape) // XK_Escape
    {
        write(1, "Window has been closed\n", 24);
        mlx_destroy_window(data->mlx_connection, data->mlx_window);
        // mlx_destroy_display(data->mlx_connection);
        free(data->mlx_connection);
        free(data);
        exit (1);
    }
    printf("The %c key has been pressed\n", keysym - 32);
    return (0);
}

int   cross_event(t_mlx_data *data)
{
    write(1, "Window has been closed\n", 24);
    mlx_destroy_window(data->mlx_connection, data->mlx_window);
    free(data->mlx_connection);
    free(data);
    exit(1);
    return (0);
} 

int main(int argc, char **argv)
{
    t_mlx_data  *data;
    t_point    **points;
    int i;

    if (argc != 2)
    {
        ft_putstr_fd("Error bad number of arguments\n", 2);
        exit(1);
    }
    points = parse_fd(argv);
    data = create_window();
    draw(&data);
    projection(&points, argv);
    i = 0;
    while (points[i])
    {
        mlx_pixel_put(data->mlx_connection, data->mlx_window, points[i]->x_proj, points[i]->y_proj, points[i]->color);
        i++;
    }


    mlx_key_hook(data->mlx_window, &handle_input, data);
    mlx_hook(data->mlx_window, 17, 0, &cross_event, data);
    free_points_tab(points);
    free(data->img);
    mlx_loop(data->mlx_connection);
}


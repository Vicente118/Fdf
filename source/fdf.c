#include "fdf.h"


int   cross_event(t_mlx_data *data)
{
    write(1, "Window has been closed\n", 24);
    mlx_destroy_window(data->mlx_connection, data->mlx_window);
    free(data->mlx_connection);
    free(data);
    // free_points_tab(data->point);
    free(data->img);  
    exit(1);
    return (0);
} 


int main(int argc, char **argv)
{
    t_mlx_data  *data;
    t_point    *points;
    int i;

    if (argc != 2)
    {
        ft_putstr_fd("Error bad number of arguments\n", 2);
        exit(1);
    }
    points = parse_fd(argv);
    data = create_window();


    projection(points, argv);
    data->point = points;
    draw(data, points);
    mlx_key_hook(data->mlx_window, &handle_key, data);

    // mlx_hook(data->mlx_window, 02, 0, key_press, data);
    // mlx_hook(data->mlx_window, 03, 0, key_release, data);
    // mlx_loop_hook(data->mlx_connection, rotation_x, data);

    mlx_hook(data->mlx_window, 17, 0, &cross_event, data);  
    mlx_loop(data->mlx_connection);
}


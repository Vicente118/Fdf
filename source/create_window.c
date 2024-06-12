#include "fdf.h"

t_mlx_data    *create_window(void)
{
    t_mlx_data *data;

    data = malloc(sizeof(t_mlx_data));
    data->img = malloc(sizeof(t_img));
    data->mlx_connection = mlx_init();
    if (!data->mlx_connection)
        exit_malloc();
    data->mlx_window = mlx_new_window(data->mlx_connection,
                                        HEIGHT, WIDTH, "Fdf");
    if (!data->mlx_window)
    {
        // mlx_destroy_display(data->mlx_connection);
        free(data->mlx_connection);
        exit_malloc();
    }
    return (data);
}


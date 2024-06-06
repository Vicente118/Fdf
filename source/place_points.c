#include "fdf.h"

void    place_points(t_point **points, t_mlx_data *data)
{
    int i;

    i = 0;
    while (points[i])
    {
        mlx_pixel_put(data->mlx_connection, data->mlx_window,
                        (sqrt(3) / 2) * (points[i]->x - points[i]->y),
                         (1 / 2) * (points[i]->x + points[i]->y) - points[i]->z,
                         0xffffff);
        i += 1;
    }
}
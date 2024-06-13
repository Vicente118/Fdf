#include "fdf.h"

void    draw_menu(t_mlx_data *data, t_point *points)
{
    int i;
    int j;
    int pixel;

    (data)->img->img_ptr = mlx_new_image((data)->mlx_connection, 1980, 1080);
    (data)->img->img_pixels_ptr = mlx_get_data_addr((data)->img->img_ptr,
                                                    &((data)->img->bits_per_pixel),
                                                    &((data)->img->size_line),
                                                    &((data)->img->endian));
    i = 0;
    while (i < 1080)
    {
        j = 350;
        while (j < 1980)
        {
            pixel = (i * (data)->img->size_line) + (j * 4);
            ((data)->img->img_pixels_ptr)[pixel + 0] = 0x16;
            ((data)->img->img_pixels_ptr)[pixel + 1] = 0x16;
            ((data)->img->img_pixels_ptr)[pixel + 2] = 0x15;
            ((data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
            j++;
        }
        i++;
    }
    i = 0;
    while (points[i].x != -1)
    {
        draw_point(data, (points)[i].x_proj, (points)[i].y_proj, (points)[i].color);
        i++;
    }
    i = 0;
    while (i < 1080)
    {
        j = 0;
        while (j < 350)
        {
            pixel = (i * (data)->img->size_line) + (j * 4);
            ((data)->img->img_pixels_ptr)[pixel + 0] = 0x2B;
            ((data)->img->img_pixels_ptr)[pixel + 1] = 0x28;
            ((data)->img->img_pixels_ptr)[pixel + 2] = 0x26;
            ((data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
            j++;
        }
        i++;
    }
    mlx_put_image_to_window((data)->mlx_connection, (data)->mlx_window, (data)->img->img_ptr, 0, 0);
}

// void    draw_background(t_mlx_data **data)
// {
//     int i;
//     int j;
//     int pixel;

//     (*data)->img->img_ptr = mlx_new_image((*data)->mlx_connection, 1630, 1080);
//     (*data)->img->img_pixels_ptr = mlx_get_data_addr((*data)->img->img_ptr,
//                                                     &((*data)->img->bits_per_pixel),
//                                                     &((*data)->img->size_line),
//                                                     &((*data)->img->endian));
//     i = 0;
//     while (i < 1080)
//     {
//         j = 350;
//         while (j < 1980)
//         {
//             pixel = (i * (*data)->img->size_line) + (j * 4);
//             ((*data)->img->img_pixels_ptr)[pixel + 0] = 0x16;
//             ((*data)->img->img_pixels_ptr)[pixel + 1] = 0x16;
//             ((*data)->img->img_pixels_ptr)[pixel + 2] = 0x15;
//             ((*data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window((*data)->mlx_connection, (*data)->mlx_window, (*data) ->img->img_ptr, 350, 0);
// }

void    text_menu(t_mlx_data *data)
{
    int color;

    color = 0xE7E5E5; 
    mlx_string_put(data->mlx_connection, data->mlx_window, 115, 50, color, "--- FDF ---");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 130, color, "- Horizontal translation : arrows");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 170, color, "- Vertical translation : arrows");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 210, color, "- Zoom in : press I");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 250, color, "- Zoom out : press O");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 290, color, "- X axe rotation : press X");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 330, color, "- Y axe rotation : press Y");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 370, color, "- Z axe rotation : press Z");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 410, color, "- Press SPACE to rotate X Y Z");
    mlx_string_put(data->mlx_connection, data->mlx_window, 12, 450, color, "- Press ESC to close the window");
}

void    draw(t_mlx_data *data, t_point *points)
{
    draw_menu(data, points);
    text_menu(data);
}


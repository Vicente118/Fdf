#include "fdf.h"

void    draw_menu(t_mlx_data **data)
{
    int i;
    int j;
    int pixel;

    (*data)->img->img_ptr = mlx_new_image((*data)->mlx_connection, 350, 1080);
    (*data)->img->img_pixels_ptr = mlx_get_data_addr((*data)->img->img_ptr,
                                                    &((*data)->img->bits_per_pixel),
                                                    &((*data)->img->size_line),
                                                    &((*data)->img->endian));
    i = 0;
    while (i < 1080)
    {
        j = 0;
        while (j < 350)
        {
            pixel = (i * (*data)->img->size_line) + (j * 4);
            ((*data)->img->img_pixels_ptr)[pixel + 0] = 0x41;
            ((*data)->img->img_pixels_ptr)[pixel + 1] = 0x39;
            ((*data)->img->img_pixels_ptr)[pixel + 2] = 0x35;
            ((*data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
            j++;
        }
        i++;
    }
    mlx_put_image_to_window((*data)->mlx_connection, (*data)->mlx_window, (*data) ->img->img_ptr, 0, 0);
}

void    draw_background(t_mlx_data **data)
{
    int i;
    int j;
    int pixel;

    (*data)->img->img_ptr = mlx_new_image((*data)->mlx_connection, 1630, 1080);
    (*data)->img->img_pixels_ptr = mlx_get_data_addr((*data)->img->img_ptr,
                                                    &((*data)->img->bits_per_pixel),
                                                    &((*data)->img->size_line),
                                                    &((*data)->img->endian));
    i = 0;
    while (i < 1080)
    {
        j = 350;
        while (j < 1980)
        {
            pixel = (i * (*data)->img->size_line) + (j * 4);
            ((*data)->img->img_pixels_ptr)[pixel + 0] = 0x2B;
            ((*data)->img->img_pixels_ptr)[pixel + 1] = 0x28;
            ((*data)->img->img_pixels_ptr)[pixel + 2] = 0x26;
            ((*data)->img->img_pixels_ptr)[pixel + 3] = 0x00;
            j++;
        }
        i++;
    }
    mlx_put_image_to_window((*data)->mlx_connection, (*data)->mlx_window, (*data) ->img->img_ptr, 350, 0);
}

void    draw(t_mlx_data **data)
{
    draw_menu(data);
    draw_background(data);
}
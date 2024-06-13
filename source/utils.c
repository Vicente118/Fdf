#include "fdf.h"

void draw_point(t_mlx_data *data, int x, int y, int color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) 
	{
        int pixel = (y * data->img->size_line) + (x * (data->img->bits_per_pixel / 8));
        if (data->img->endian == 0) 
		{
            data->img->img_pixels_ptr[pixel + 0] = (color & 0xFF);       // Blue component
            data->img->img_pixels_ptr[pixel + 1] = (color >> 8) & 0xFF;  // Green component
            data->img->img_pixels_ptr[pixel + 2] = (color >> 16) & 0xFF; // Red component
            data->img->img_pixels_ptr[pixel + 3] = (color >> 24) & 0xFF; // Alpha component
        } 
		else 
		{
            data->img->img_pixels_ptr[pixel + 0] = (color >> 24) & 0xFF; // Alpha component
            data->img->img_pixels_ptr[pixel + 1] = (color >> 16) & 0xFF; // Red component
            data->img->img_pixels_ptr[pixel + 2] = (color >> 8) & 0xFF;  // Green component
            data->img->img_pixels_ptr[pixel + 3] = (color & 0xFF);       // Blue component
        }
    }
}

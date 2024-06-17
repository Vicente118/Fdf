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

void draw_line(t_mlx_data *data, int x0, int y0, int x1, int y1, int color0, int color1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        // Calcul du ratio pour le dégradé
        float ratio = 0.0;
        if (dx > dy)
            ratio = (x0 - x1) / (float)dx;
        else
            ratio = (y0 - y1) / (float)dy;

        // Interpolation des couleurs
        int red = (1 - ratio) * ((color0 >> 16) & 0xFF) + ratio * ((color1 >> 16) & 0xFF);
        int green = (1 - ratio) * ((color0 >> 8) & 0xFF) + ratio * ((color1 >> 8) & 0xFF);
        int blue = (1 - ratio) * (color0 & 0xFF) + ratio * (color1 & 0xFF);
        int color = (red << 16) | (green << 8) | blue;

        draw_point(data, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

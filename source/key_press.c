#include "fdf.h"

int	key_press(int keysym, t_mlx_data *data)
{
	data->key_pressed[keysym] = 1;
	return (0);
}

int key_release(int keysym, t_mlx_data *data)
{
	data->key_pressed[keysym] = 0;
	return (0);
}
#include "fdf.h"

int		ft_min(char **argv)
{
	int lignes = count_line(argv);
	int col = count_col(argv);

	if ((((1920 - 350) / col) / 2) < (1080 / lignes) / 2)
	{
		return (((1920 - 800) / col) / 2);
	}
	else
		return ((1080 / lignes) / 2);
}

int		zoom_factor(char **argv)
{
	float	zoom;

	zoom = ft_min(argv);
	return (zoom);
}

void	projection(t_point ***points, char **argv)
{
	int	i;
	int	zoom;

	i = 0;
	zoom = zoom_factor(argv);
	while ((*points)[i])
	{
		(*points)[i]->x *= zoom;
		(*points)[i]->y *= zoom;
		(*points)[i]->z *= zoom;
		// (*points)[i]->x = (*points)[i]->x * (sqrt(2)/2) + (*points)[i]->z * (sqrt(2)/2);
		// (*points)[i]->z = -1 * (*points)[i]->x * (sqrt(2)/2) + (*points)[i]->z * (sqrt(2)/2);
		(*points)[i]->x_proj = ((*points)[i]->x - (*points)[i]->y) * (sqrt(3) / 2);
		(*points)[i]->y_proj = (((*points)[i]->x + (*points)[i]->y) / 2) - (*points)[i]->z;
		(*points)[i]->x_proj += 350 + (1920 - 350) / 2;
		(*points)[i]->y_proj += (1080 / 2) - 200;
		i++;
	}
}
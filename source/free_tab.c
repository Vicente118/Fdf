#include "fdf.h"

void    free_tab(char **array)
{
    int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
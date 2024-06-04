#include "fdf.h"

void    exit_error(void)
{
    perror("Error");
    exit(1);
}

void    exit_malloc(void)
{
    write(2, "Error memory allocation\n", 24);
    exit (1);
}
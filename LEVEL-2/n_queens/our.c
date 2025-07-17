
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *map;
int     size;

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

void print_map(void)
{
    int i = -1;
    while (++i < size)
    {
        fprintf(stdout, "%d", map[i]);
        if (i < size - 1)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}

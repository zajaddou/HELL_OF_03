
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     size;
char    *map;

void    print_map(void)
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

void    algo(int col)
{
    if (col == size)
        return (print_map());
    int row = -1;
    while (++row < size)
    {
        int i = -1;
        while (++i < col)
            if ((abs(i - col) == abs(map[i] - row)) || (map[i] == row))
                break;
        if (i == col)
        {
            map[col] = row;
            algo(col + 1);
        }
    }
}

int     main(int ac, char *av[])
{
    if (ac != 2)
        return (write(1, "\n", 1), 0);
    size = atoi(av[1]);
    if (size <= 3)
        return (write(1, "\n", 1), 0);
    map = malloc(sizeof(int) * size);
    algo(0);
    free(map);
    return (0);
}
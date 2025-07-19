#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     size;
char    *map;

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

void algo(int col)
{
    if (col == size)
        return (print_map());
    int row = -1;
    while (++row < size)
    {
        int i = -1;
        while (++i < col)
            if ((map[i] == row) || (abs(map[i] - row) == abs(i - col)))
                break;
        if (col == i)
        {
            map[col] = row;
            algo(col + 1);
        }
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return (write(1, "\n", 1), 0);
    size = atoi(av[1]);
    if (size > 1 && size < 4)
        return (write(1, "\n", 1), 0);
    map = malloc(sizeof(int) * size);
    if (!map)
        return (1);
    algo(0);
    free(map);
    return (0);
}
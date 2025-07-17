
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

int is_safe(int row, int col)
{
    int i = -1;
    while (++i < col)
    {
        if (map[i] == row)
            return (0);
        if (ft_abs(map[i] - row) == ft_abs(i - col))
            return (0);
    }
    return (1);
}

void solve(int col)
{
    if (col == size)
    {
        print_map();
        return ;
    }
    int row = -1;
    while (++row < size)
    {
        if (is_safe(row, col))
        {
            map[col] = row;
            solve(col + 1);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 0);
    size = atoi(av[1]);
    if (size <= 3)
        return (write(1, "\n", 1), 0);
    map = malloc(sizeof(int) * size);
    if (!map)
        return (1);
    solve(0);
    free(map);
    return (0);
}
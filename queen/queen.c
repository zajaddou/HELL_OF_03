#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_solution(int *column, int n)
{
    int i = 0;
    while (i < n)
    {
        fprintf(stdout, "%d", column[i]);
        if (i != n - 1)
            fprintf(stdout, " ");
        i++;
    }
    fprintf(stdout, "\n");
}

int ft_abs(int x)
{
    return (x < 0 ? -x : x);
}

int no_conflict(int col, int row, int *column)
{
    int prev = 0;

    while (prev < col)
    {
        if (column[prev] == row)
            return (0);
        if (ft_abs(column[prev] - row) == ft_abs(prev - col))
            return (0);
        prev++;
    }
    return (1);
}

void n_queen(int n, int *column, int *row, int col)
{
    int y = 0;
    if (col == n)
    {
        print_solution(column, n);
        return;
    }
    while (y < n)
    {
        if (!row[y] && no_conflict(col, y, column))
        {
            column[col] = y;
            row[y] = 1;
            n_queen(n, column, row, col + 1);
            row[y] = 0;
        }
        y++;
    }
}

int main(int argc, char **argv)// n = 4
{
    if (argc != 2 || argv[1][0] == '\0')
        return (1);
    int n = atoi(argv[1]);
    if (n <= 0 || n > 100)
        return (1);
    int column[100] = {0};
    int row[100] = {0};
    n_queen(n, column, row, 0);
    return (0);
}

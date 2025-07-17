
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *board;
int board_size;

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return n;
}

void print_solution(void)
{
    for (int i = 0; i < board_size; i++)
    {
        fprintf(stdout, "%d", board[i]);
        if (i < board_size - 1)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}

int is_safe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row)
            return 0;
        if (ft_abs(board[i] - row) == ft_abs(i - col))
            return 0;
    }
    return 1;
}

void solve(int col)
{
    if (col == board_size)
    {
        print_solution();
        return ;
    }
    for (int row = 0; row < board_size; row++)
    {
        if (is_safe(row, col))
        {
            board[col] = row;
            solve(col + 1);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 0);
    int n = atoi(av[1]);
    if (n <= 3)
        return (write(1, "\n", 1), 0);
    board_size = n;
    board = malloc(sizeof(int) * board_size);
    if (!board)
        return 1;
    solve(0);
    free(board);
    return (0);
}
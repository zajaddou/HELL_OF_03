
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *s;
int     len;
char    *res;
int     *used;

void permutation(int dep)
{
    if (dep == len)
    {
        write(1, res, len);
        write(1, "\n", 1);
        return ;
    }
    int i = -1;
    while (++i < len)
    {
        if (!used[i])
        {
            used[i] = !used[i];
            res[dep] = s[i];
            permutation(dep + 1);
            used[i] = !used[i];
        }
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return (write(1, "\n", 1), 0);
    s = av[1];
    len = strlen(s);
    res = malloc(len + 1);
    used = calloc(len, sizeof(int));
    if (!used || !res)
        return (1);
    permutation(0);
    free(res);
    free(used);
    return (0);
}

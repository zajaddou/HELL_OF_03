
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

char    *s;
char    *res;
int     len;
int     *used;

void    permute(int dep)
{
    if (dep == len)
    {
        write(1, res, len);
        write(1, "\n", 1);
        return ;
    }
    int i = 0;
    while (i < len)
    {
        if (!used[i])
        {
            used[i] = 1;
            res[dep] = s[i];
            permute(dep + 1);
            used[i] = 0;
        }
        i++;
    }
}

int    main(int ac, char **av)
{
    if (ac != 2)
        return (write (1, "\n", 1), 0);
    s = av[1];
    // sort(s);
    len = strlen(s);
    res = malloc(len + 1);
    used = calloc(len, sizeof(int));
    if (!res || !used)
        return (1);
    permute(0);
    free(res);
    free(used);
    return (0);
}
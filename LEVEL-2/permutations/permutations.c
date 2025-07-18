
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void    permute(char *s, char *out, int *used, int depth, int len)
{
    if (depth == len)
    {
        write(1, out, len);
        write(1, "\n", 1);
        return ;
    }
    int i = 0;
    while (i < len)
    {
        if (!used[i])
        {
            used[i] = 1;
            out[depth] = s[i];
            permute(s, out, used, depth + 1, len);
            used[i] = 0;
        }
        i++;
    }
}

int    main(int ac, char **av)
{
    if (ac != 2)
        return (write (1, "\n", 1), 0);
    int len = strlen(av[1]);
    char *str = av[1];
    char *out = malloc(len + 1);
    int *used = calloc(len, sizeof(int));
    if (!out || !used)
        return (1);
    // sort(str);
    permute(str, out, used, 0, len);
    free(out);
    free(used);
    return (0);
}

#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char    *ft_strdup(char *src)
{
    int i = 0;
    char *res;

    while (src[i])
        i++;
    res = malloc(i + 1);
    i = -1;
    while(src[++i])
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}

char    *get_next_line(int fd)
{
    
}
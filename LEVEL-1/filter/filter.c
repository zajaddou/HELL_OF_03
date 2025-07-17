
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int is_found(char *buff, char *need)
{
    int i = -1;
    while (need[++i])
        if (buff[i] != need[i])
            return (0);
    while (--i >= 0)
        write(1, "*", 1);
    return (1);
}

int main(int argc, char *argv[])
{
    char    buff[1000000];
    int     r;
    int     i;
    
    if (argc != 2 || !argv[1][0])
        return (1);
    while (1)
    {
        r = read(0, buff, BUFFER_SIZE);
        if (r < 0)
            return (perror("Error"), 1);
        if (r == 0)
            break ;
        buff[r] = '\0';
        i = 0;
        while (buff[i])
        {
            if (is_found(&buff[i], argv[1]))
                i += strlen(argv[1]);
            else
                write(1, &buff[i++], 1);
        }
    }
    return (0);
}

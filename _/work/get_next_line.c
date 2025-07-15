
#include <unistd.h>
#include <stdlib.h>

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
    while (src[++i])
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}

char    *get_next_line(int fd)
{
    static char buff[700000];
    char        line[70000];
    static int  r;
    static int  p;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (p >= r)
        {
            p = 0;
            r = read(fd, buff, BUFFER_SIZE);
            if (r <= 0)
                break ;
        }
        line[i++] = buff[p++];
        if (buff[p - 1] == '\n' || i >= (int)sizeof(line) - 1)
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}


// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line); 
//     }
//     close(fd);
//     return 0;
// }

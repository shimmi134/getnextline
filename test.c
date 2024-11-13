#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
/*
int main(int argc, char *argv[])
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}*/

int main(int argc, char **argv)
{
    int fd;
    char *line;

    fd = open("test.c", O_RDONLY);
	printf("FD: %i",fd);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}

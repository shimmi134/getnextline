#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("hi.txt",O_RDONLY);
	char *arr = get_next_line(fd);
	printf("%s\n",arr);
	free (arr);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main()
{
	int fd = open("test.txt", O_RDWR | O_CREAT , 777);
	char *line;
	// write(fd, "123456789369852147", 19);
	int fd2 = open("41_with_nl", O_RDWR);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd2);
	}
	//system("leaks -q a.out");
}

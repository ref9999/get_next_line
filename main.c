#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("test.txt", O_RDONLY);
  while (1){
 	 next_line = get_next_line(fd);
  	if (next_line == NULL)
		break;
	count++;
  	printf("[%d]:%s\n", count, next_line);
	free(next_line);
  	next_line = NULL;
  	// system("leaks -q a.out");
  }
  close(fd);
  return (0);
}


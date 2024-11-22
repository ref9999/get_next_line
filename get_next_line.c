
// char	*get_next_line(int fd)
// {
// 	int readit;
// 	char *buff;

// 	readit = read(fd, buff, 3);
// 	buff = ft_calloc(3 + 1, sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	return (buff);
// }

# include <unistd.h>
#include "get_next_line.h"




void    print_newline_helper(char *buffer)
{

	while (*buffer &&  *buffer != '\0')
	{
		if (*buffer == '\n')
		{
			*buffer= '\\';
		}
		// printf("%c",*buffer);
		buffer++;
	}
}




/*function to read from a file*/

static char  *readlines(int fd)
{
	int			bread;
	char		*buffer;
	static int	count;

	buffer = ft_calloc (BUFFERSIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bread = read(fd, buffer, BUFFERSIZE);
	if (bread <= 0)
	{
		free(buffer);
		return (NULL);
	}
  return (buffer);
}

/*getnextline*/

char	*get_next_line(int fd)
{
	char *buff;

	buff = readlines(fd);
	return (buff);

}

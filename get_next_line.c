
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
##################################################################################





######################################
getnexlinr
#################################3

char *get_next_line(int fd)
{	
	static char *buffer;
	char  *line;

	// if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0) 
	// 	return (NULL);
	// if (!buffer)
	// 	buffer = ft_calloc(1, sizeof (char)); 
	// if (!ft_strchr(buffer, '\n'))
	// 	buffer = read_from_file(buffer, fd);
 	// if (!buffer)
  	// 	return (free(buffer), NULL);

 	line = line_extraction(buffer);
 	buffer = joining(buffer);
 	return (line);
}


######################################
reading from the file 
########################################


char *read_from_file(char *buffer, int fd)
{
 	char *buffer2;
 	int  bytes_read;

 	buffer2 = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
 	if (!buffer2)
  		return (NULL);
 	bytes_read = 1;
 	while (bytes_read > 0)
 	{
  		bytes_read = read(fd, buffer2, BUFFER_SIZE);
  		if (bytes_read == -1)
   			return (free(buffer2), NULL);
  		buffer2[bytes_read] = '\0';
  		buffer = append_buffer(buffer, buffer2);
  		if (ft_strchr(buffer, '\n'))
   			break ;
 	}
 	free (buffer2);
 	return (buffer);
}


######################################
appending  // joinig the buffer
######################################


char *append_buffer(char *buffer, char *read_buffer)
{
 	char *tmp;

 	tmp = ft_strjoin(buffer, read_buffer);
 	free(buffer);
 	return (temp);
}
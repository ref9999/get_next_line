#include "get_next_line.h"

char *extract_lines(char *buffer, char *buffer2)
{
	char *new_buffer;
	size_t i;
	size_t j;

	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) + ft_strlen(buffer2) + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	j = 0;
	while (buffer2[j])
	{
		new_buffer[i++] = buffer2[j];
		if (buffer2[j++] == '\n')
			break;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char *obtain_remaining(char *buffer)
{
	char *new_buffer;
	char *newline_pos;
	size_t i;
	size_t j;

	newline_pos = ft_strchr(buffer, '\n');
	if (!newline_pos)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)calloc((ft_strlen(newline_pos + 1) + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);

	i = 0;
	j = newline_pos - buffer + 1;
	while (buffer[j])
	{
		new_buffer[i++] = buffer[j++];
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*append_buffer(char *buffer, char *buffer2)
{
 	char *tmp;

 	tmp = ft_strjoin(buffer, buffer2);
 	free(buffer);
 	return (tmp);
}

char	*read_from_file(char *buffer, int fd)
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

char *get_next_line(int fd)
{
	static char *buffer;
	char  *line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof (char));
	if (!ft_strchr(buffer, '\n'))
		buffer = read_from_file(buffer, fd);
 	if (!buffer)
  		return (free(buffer), NULL);
	if (!buffer)
		return (NULL);
 	line = extract_lines(NULL, buffer);
 	buffer = obtain_remaining(buffer);
 	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:40:53 by riel-fas          #+#    #+#             */
/*   Updated: 2024/12/02 13:23:55 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


// This function cleans up the stash
// by freeing memory and returning the remaining
// part of the string after the newline character.
char	*ft_freeline(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[x] && stash[x] != '\n')
		x++;
	if (!stash[x])
	{
		free(stash);
		return (NULL);
	}
	line = ft_substr(stash, x + 1, ft_strlen(stash) - x - 1);
	free(stash);
	return (line);
}

// This function reads from the file
// and appends the content to stash.
char	*read_from_file(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		buffer_read;

	while (1)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
			break ;
		buffer[buffer_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (buffer_read < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}


// This function extracts a line from stash.
char	*get_line_from_stash(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	while (stash[x] && stash[x] != '\n')
		x++;
	line = ft_substr(stash, 0, x + (stash[x] == '\n'));
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	#include <limits.h>

	static char *stash[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash[fd] = read_from_file(fd, stash[fd], buffer);
	free(buffer);
	if (!stash[fd])
		return (NULL);
	line = get_line_from_stash(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = ft_freeline(stash[fd]);
	return (line);
}


// get_next_line(fd)
//     ├── validate inputs
//     ├── allocate buffer
//     ├── read_from_file(fd, stash[fd], buffer)
//     │   ├── read data into buffer
//     │   ├── append buffer to stash[fd]
//     │   └── return updated stash[fd]
//     ├── get_line_from_stash(stash[fd])
//     │   ├── find newline in stash[fd]
//     │   ├── extract line from stash[fd]
//     │   └── return line
//     ├── ft_freeline(stash[fd])
//     │   ├── find newline in stash[fd]
//     │   ├── free part before newline
//     │   └── return remaining stash[fd]
//     └── return line

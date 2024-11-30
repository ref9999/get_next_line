/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:39 by riel-fas          #+#    #+#             */
/*   Updated: 2024/11/30 09:56:33 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		free (stash);
		return (NULL);
	}
	line = ft_substr(stash, x + 1, ft_strlen(stash) - x - 1);
	free(stash);
	if (!line)
	{
		return (NULL);
	}
	return (line);
}

char	*read_from_file(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int 	buffer_read;

	while (1)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == 0)
			break;
		buffer[buffer_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (buffer_read < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_from_file(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_freeline(stash);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:39 by riel-fas          #+#    #+#             */
/*   Updated: 2024/11/29 12:32:36 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	cc;

	temp = (char *)s;
	cc = (char)c;
	while (*temp)
	{
		if (*temp == cc)
			return (temp);
		temp++;
	}
	if (cc == '\0')
		return (temp);
	return (0);
}

char	*ft_freeline(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[x] && stash[x] != '\n')
		x++;
	if (stash[x] == '\0')
		return (NULL);
	line = ft_substr(stash, x + 1, ft_strlen(stash) - x - 1);
	if (!line)
		return (NULL);
	stash[x + 1] = '\0';
	return (line);
}

char	*read_from_file(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		buffer_read;

	buffer_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer_read > 0)
	{
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
	if (buffer_read == -1)
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

	if (fd < 0 || BUFFER_SIZE <= 0)
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

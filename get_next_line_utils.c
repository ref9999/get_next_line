/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:58 by riel-fas          #+#    #+#             */
/*   Updated: 2024/11/29 17:03:28 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*str;

// 	if (s)
// 	{
// 		str = (char *)malloc(sizeof(char) * (len + 1));
// 		if (!str)
// 			return (NULL);
// 		i = 0;
// 		while (i < len)
// 		{
// 			str[i] = s[start];
// 			start++;
// 			i++;
// 		}
// 		str[i] = '\0';
// 		return (str);
// 	}
// 	return (NULL);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	i;
    size_t	s_len;
    char	*str;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

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

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*x;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	x = (char *)malloc(count * size);
	if (!x)
		return (NULL);
	ft_bzero(x, count * size);
	return (x);
}

void	ft_bzero(void *s, size_t n)
{
	if (!n)
		return ;
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len)
	{
		*ptr++ = c;
		len --;
	}
	return (b);
}

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
	size_t	len;
	char	*copy;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	ft_strlcat(copy, s2, len);
	return (copy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	x;

	len = ft_strlen(src);
	x = 0;
	if (!dstsize)
		return (len);
	while (src[x] != '\0' && x < dstsize - 1)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;
	size_t	i;
	size_t	j;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (dstsize == 0)
		return (lens);
	if (dstsize <= lend)
		return (dstsize + lens);
	i = lend;
	j = 0;
	while (src[j] && (i < dstsize - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (lend + lens);
}

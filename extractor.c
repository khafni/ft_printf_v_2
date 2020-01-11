#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(src);
	if (size >= 1)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

int format_length (char *s)
{
	int length;

	length = 0;
	s++;
	while (*s != 'c' && *s != 's' && *s != 'p' &&
	*s != 'd' && *s != 'i' && *s != 'u' &&
	*s != 'x' && *s != 'X' && *s)
	{
		length++;
		s++;
	}
	return (length);
}

char *extractor(char *format)
{
	char *holder;
	int l;

	l = format_length(format);
	format++;
	holder = malloc(sizeof(char) * l);
	ft_strlcpy(holder, format, l + 1);
	return (holder);
}

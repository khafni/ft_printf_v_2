#include "utills.h"
int format_length (char *s)
{
	int length;

	length = 0;
	s++;
	while (*s != 'c' && *s != 's' && *s != 'p' &&
	*s != 'd' && *s != 'i' && *s != 'u' &&
	*s != 'x' && *s != 'X' && *s != '%' && *s)
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
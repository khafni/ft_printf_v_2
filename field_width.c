#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int field_width(char *format, va_list vlist)
{
	int fw;

	fw = 0;
	while (*format && *format != '.')
	{
		if (ft_isdigit(*format))
		{
			fw = atoi(format);
		}
		else if (*format == '*')
		{
			fw = va_arg(vlist, int);
		}
		format++;
	}
	return (fw);
}

void ft_printf(char *string, ...)
{
	va_list list;

	va_start (list, string);
	printf("%d", field_width(string, list));
	va_end(list);
}

int main()
{

	ft_printf(".*", 666);
	return (0);
}

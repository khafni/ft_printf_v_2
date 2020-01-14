#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int precision(char *format, va_list vlist)
{
	int pr;

	pr = 0;
	while (*format)
	{
		if (*format == '.')
		{
			format++;
			if (ft_isdigit(*format))
			{
				pr = atoi(format);
			}
			else if (*format == '*')
			{
				pr = va_arg(vlist, int);
			}
		}
		format++;
	}
	return (pr);
}

void ft_printf(char *string, ...)
{
	va_list list;

	va_start (list, string);
	printf("%d", precision(string, list));
	va_end(list);
}

int main()
{

	ft_printf("1337.*", 42);
	return (0);
}

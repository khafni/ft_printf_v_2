#include "ft_printf.h"

int ft_parser (const char *format, va_list args)
{
	int flags;
	int field_width;
	int presision;
	int i;

	flags = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar (*format);
			continue ;
		}
	}

}
int	ft_printf (const char *format, ...)
{
	int printed
	va_list args;
	int printf_count;

	printed = ft_parser (ft_printf_buff, format, args);
	va_end(args);

}

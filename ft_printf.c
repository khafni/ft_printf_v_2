#include "ft_printf.h"


t_format	*format_init(void)
{
	t_format *format;
	if(!(format = malloc (sizeof(t_format))))
		return (NULL);
	format->flags = 0;
	format->width = 0;
	format->presision = 0;
	format->length = 0;
	format->specifier = '0';
	return (format);
}

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
	specifier	s_list[9];
	t_format format;
	
	format = format_init();
	s_list[8] = 
	{
		{"c", ft_printf_char},
		{"s", ft_printf_string},
		{"p", ft_printf_address},
		{"d", ft_printf_integer},
		{"i", ft_printf_integer},
		{"u", ft_printf_uinteger},
		{"x", ft_printf_uhinteger},
		{"X", ft_printf_uhinteger}
	}
	printed = ft_parser (ft_printf_buff, format, args);
	va_end(args);

}

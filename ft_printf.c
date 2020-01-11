#include "ft_printf.h"

int g_flags_state = 0;

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
int flags_s_a (*format)
{
    


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
	t_format format;
	
	format = format_init();
	printed = ft_parser (ft_printf_buff, format, args);
	va_end(args);

}

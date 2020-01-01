#include "ft_printf.h"

int	ft_printf (const char *format, ...)
{
	char ft_printf_buff[1024]; // gonna change it after to be dynamic
	va_list args;
	int printf_count;
	printed = ft_vsprintf (ft_printf_buff, format, args);
	va_end(args);

}

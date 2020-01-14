#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


t_format	*format_init(void)
{
	t_format *format;
	if(!(format = malloc (sizeof(t_format))))
		return (NULL);
	format->specifier = '0';
	format->field_width = 0;
	format->precision = 0;
	format->minus = 0;
	format->plus = 0;
	format->hashtag = 0;
	format->zero = 0;

	return (format);
}
void	flags_P_filler(char *str, t_format *format)
{
	while (*str)
	{
		if (*str == '-')
			format->flags->minus += 1;
		else if (*str == '+')
			format->flags->plus += 1;
		else if (*str == '#')
			format->flags->hashtag += 1;
		else if (*str == '0')
			format->flags->zero += 1;
		str++;
	}
}


/*
**	function that gets the field width value
*/
int field_width(char *format, t_format *format, va_list vlist)
{

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
/*
** function that gets the precision value
*/

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
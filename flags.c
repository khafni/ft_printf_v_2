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
	if(!(format->flags = malloc(sizeof(t_flags))))
		return (NULL);
	format->flags->minus = 0;
	format->flags->zero = 0;
	format->flags->point = 0;
	format->flags->asterisk = 0;
	format->width = 0;
	format->presision = 0;
	format->length = 0;
	format->specifier = '0';
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
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../ft_printf.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char specifier_extractor(char *s)
{
	s++;
	while (*s)
	{
		if (*s == 'c' || *s == 's' || *s == 'p' ||
			   *s == 'd' || *s == 'i' || *s == 'u' ||
			   *s == 'x' || *s == 'X')
		{
			return (*s);
		}
		s++;
	}
	return ('@');
}

t_format *format_init(void)
{
	t_format *format;
	if (!(format = malloc(sizeof(t_format))))
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
void flags_filler(char *str, t_format *format)
{
	while (*str)
	{
		if (*str == '-')
			format->minus += 1;
		else if (*str == '+')
			format->plus += 1;
		else if (*str == '#')
			format->hashtag += 1;
		else if (*str == '0')
			format->zero += 1;
		str++;
	}
}

/*
**	function that gets the field width value
*/
void field_width_getter(char *format, t_format *holder, va_list vlist)
{
	format++;
	while (*format && *format != '.')
	{
		if (ft_isdigit(*format))
		{
			holder->field_width = atoi(format);
			break ;
		}
		else if (*format == '*')
		{
			holder->field_width = va_arg(vlist, int);
			break ;
		}
		format++;
	}
}
/*
** function that gets the precision value
*/

void precision_getter(char *format, t_format *holder, va_list vlist)
{
	while (*format)
	{
		if (*format == '.')
		{
			format++;
			if (ft_isdigit(*format))
			{
				holder->precision = atoi(format);
				break ;
			}
			else if (*format == '*')
			{
				holder->precision = va_arg(vlist, int);
				break ;
			}
		}
		format++;
	}
}

t_format *get_data (char *f_sstr, va_list vlist)
{
	t_format *container;

	container = format_init();
	container->specifier = specifier_extractor(f_sstr);
	field_width_getter(f_sstr, container, vlist);
	precision_getter(f_sstr, container, vlist);
	flags_filler (f_sstr, container);
	return (container);
}
void data_debugging (t_format *holder)
{
	printf ("specifier : %c\n", holder->specifier);
	printf ("fw : %d\n", holder->field_width);
	printf ("pr : %d\n", holder->precision);
	printf ("- : %d\n", holder->minus);
	printf ("+ : %d\n", holder->plus);
	printf ("# : %d\n", holder->hashtag);
	printf ("0 : %d", holder->zero);
}

int ft_printf(char *str, ...)
{
	va_list alist;
	t_format *format;

	va_start (alist, str);
	data_debugging(get_data(str, alist));
	va_end(alist);
	return (1);
}

int main()
{
	ft_printf("%-----++++++00*.*d", 666, 42);
	return (0);
}
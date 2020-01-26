#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "data_gathering.h"
#include "../libft/libft.h"

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
	format->value = NULL;
	return (format);
}

void flags_filler(char *str, t_format *format)
{
	str++;
	if (*str == '0')
		format->zero = 1;
	while (*str)
	{
		if (*str == '-')
			format->minus += 1;
		else if (*str == '+')
			format->plus += 1;
		else if (*str == '#')
			format->hashtag += 1;
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
		while (*format == '0')
			format++;
		if (ft_isdigit(*format))
		{
			holder->field_width = ft_atoi(format);
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
				holder->precision = ft_atoi(format);
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
void	value_get(char *format, t_format *holder, va_list vlist)
{
	int h;
	while (*format)
	{
		if (*format == '*')
			h = va_arg(vlist, int);
		format++;
	}
	if (holder->specifier != '%' && holder->specifier != '@')
	{
		if (holder->specifier == 's' || holder->specifier == 'c')
			holder->value = ft_strdup(va_arg(vlist, char *));
		else
			holder->value = ft_itoi(va_arg(vlist, int));
	}
}
/*
** the function to get the the data
*/
t_format *get_data (char *f_sstr, va_list vlist)
{
	t_format *container;

	container = format_init();
	container->specifier = specifier_extractor(f_sstr);
	field_width_getter(f_sstr, container, vlist);
	precision_getter(f_sstr, container, vlist);
	flags_filler (f_sstr, container);
	value_get(f_sstr, container, vlist);

	return (container);
}

void debugger(char *str, ...)
{
	va_list alist;
	t_format *holder;

	va_start(alist, str);
	holder = get_data(str, vlist);
	printf("s : %c \n fw : %d \n pr : %d \n mn: %d \n 0 : %d \n value : %s", holder->specifier, holder->field_width, holder->precision, holder->minus, holder->zero, holder->value);
	va_end(alist);
}
int main()
{
	bobo("%*.*d", 88, 42, "fuck");
	return (0);
}
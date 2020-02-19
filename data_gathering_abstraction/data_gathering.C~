#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../utills/utills.h"
#include "data_gathering.h"


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

void existence_analyser (char *str, t_format *holder)
{
	str++;
	if (*str == '0' && ft_strchr("123456789.*", *(str + 1)))
		holder->flags_existence |= FW_ZERO;
}

t_format *data_init(void)
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
	format->flags_existence = 0;
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
		{
			if (*(format + 1) == '.')
				{
					holder->field_width = 0;
					break ;
				}
			format++;
		}
		if (ft_isdigit(*format))
		{
			holder->field_width = ft_atoi(format);
			break ;
		}
		else if (*format == '*')
		{
			holder->flags_existence |= FS;
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
			holder->flags_existence  |= PRECISION;
			format++;
			if (ft_isdigit(*format))
			{
				holder->precision = ft_atoi(format);
				break ;
			}
			else if (*format == '*')
			{
				holder->flags_existence |= SS;
				holder->precision = va_arg(vlist, int);
				break ;
			}
		}
		format++;
	}
}
void	value_get(t_format *holder, va_list vlist)
{
	if (holder->specifier != '%' && holder->specifier != '@')
	{
		if (holder->specifier == 's' || holder->specifier == 'c')
			holder->value = ft_strdup(va_arg(vlist, char *));
		else if (holder->specifier == 'd' || holder->specifier == 'i')
			holder->value = ft_ltoa(va_arg(vlist, int));
		else
			holder->value = ft_ltoa(va_arg(vlist, unsigned int));
	}
}
/*
** the function to get the the data
*/
t_format *get_data (char *f_sstr, va_list vlist)
{
	t_format *container;

	container = data_init();
	container->specifier = specifier_extractor(f_sstr);
	existence_analyser(f_sstr, container);
	field_width_getter(f_sstr, container, vlist);
	precision_getter(f_sstr, container, vlist);
	flags_filler (f_sstr, container);
	value_get(container, vlist);

	return (container);
}
/*
void debugger(char *str, ...)
{
	va_list alist;
	t_format *holder;

	va_start(alist, str);
	holder = get_data(str, alist);
	ft_putchar_fd(holder->specifier, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->field_width ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->precision ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->minus ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->zero ,1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(holder->value, 1);
	va_end(alist);
}



int main()
{
    debugger("%u", -1);
	printf("\n%u", -1);
    return (0);
}
*/

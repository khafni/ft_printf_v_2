#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "data_gathering.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > 9223372036854775807)
			return (neg < 0 ? 0 : -1);
		i++;
	}
	return (neg * nb);
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
			printf("greger\n");
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
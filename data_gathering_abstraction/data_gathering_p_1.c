/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_gathering_p_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:24:36 by khafni            #+#    #+#             */
/*   Updated: 2020/02/23 01:11:20 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_gathering.h"

char			specifier_extractor(char *s)
{
	s++;
	while (*s)
	{
		if (*s == 'c' || *s == 's' || *s == 'p' ||
			*s == 'd' || *s == 'i' || *s == 'u' ||
			*s == 'x' || *s == 'X' || *s == '%')
		{
			return (*s);
		}
		s++;
	}
	return ('@');
}

void			existence_analyser(char *str, t_format *holder)
{
	str++;
	while (*str == '0' && *(str + 1) == '0')
		str++;
	if (*str == '0' && ft_strchr("123456789.*", *(str + 1)))
		holder->flags_existence |= FW_ZERO;
}

t_format		*data_init(void)
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
	format->s_v = '0';
	return (format);
}

void			flags_filler(char *str, t_format *format)
{
	str++;
	if (*str == '0')
		format->zero = 1;
	while (*str && *str != format->specifier)
	{
		if (*str == '-' || format->field_width < 0)
			format->minus += 1;
		str++;
	}
}

/*
** this function does not just get the field_width value but also stores 
** the state of existence of the fieldwidth asterisk using the bitwise or
** operator and storing the state of existence in an int
*/

void			field_width_getter(char *format,
t_format *holder, va_list vlist)
{
	format++;
	while (*format && *format != '.' && *format != holder->specifier)
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

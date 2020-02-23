/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_gathering_p_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:34:43 by khafni            #+#    #+#             */
/*   Updated: 2020/02/23 17:40:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_gathering.h"

/*
**	the function also stores the state of existence of the precision
**	point and the precision astersik
*/

void
	precision_getter(char *format, t_format *holder, va_list vlist)
{
	while (*format && *format != holder->specifier)
	{
		if (*format == '.')
		{
			holder->flags_existence |= PRECISION;
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

/*
** this function exists because when the original printf is given a null pointer
** as a value for the s specifier , it prints the string "(null)" so i chose
** to my function fall in that case it gather the string "(null)" as value for
** the s specifier instead of a null pointer
*/

char
	*s_transform_n_sn(char *p)
{
	if (!p)
		p = ft_strdup("(null)");
	return (p);
}

void
	value_get(t_format *holder, va_list vlist)
{
	char *tmp;

	if (holder->specifier == 's')
	{
		holder->value = ft_strdup(va_arg(vlist, char *));
		holder->value = s_transform_n_sn(holder->value);
	}
	else if (holder->specifier == 'c')
		holder->s_v = va_arg(vlist, int);
	else if (holder->specifier == '%')
		holder->s_v = '%';
	else if (holder->specifier == 'd' || holder->specifier == 'i')
		holder->value = ft_ltoa(va_arg(vlist, int));
	else if (holder->specifier == 'x' || holder->specifier == 'X')
		holder->value = dec_to_hex(va_arg(vlist, unsigned int));
	else if (holder->specifier == 'p')
	{
		holder->value = dec_to_hex(va_arg(vlist, size_t));
		tmp = holder->value;
		holder->value = ft_strjoin("0x", holder->value);
		free(tmp);
	}
	else
		holder->value = ft_ltoa(va_arg(vlist, unsigned int));
}

/*
** this is the only function that is passed to the other interfaces
*/

t_format
	*get_data(char *f_sstr, va_list vlist)
{
	t_format *container;

	container = data_init();
	container->specifier = specifier_extractor(f_sstr);
	existence_analyser(f_sstr, container);
	field_width_getter(f_sstr, container, vlist);
	precision_getter(f_sstr, container, vlist);
	flags_filler(f_sstr, container);
	value_get(container, vlist);
	return (container);
}

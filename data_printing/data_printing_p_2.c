/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_printing_p_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:26:12 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 03:25:44 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_printing.h"

void
	p_value(t_result *result)
{
	if (result->data->specifier == 'c')
		ft_putchar_fd(result->data->s_v, 1);
	else if (result->data->specifier == '%')
		ft_putchar_fd('%', 1);
	else if (result->data->specifier == 's')
		ft_print_max_s(result);
	else
		p_num(result);
}

void
	unsigned_minus_removed(t_result *result)
{
	char c;

	c = result->data->specifier;
	if (c == 'd' || c == 'i')
		ft_putchar_fd('-', 1);
}

void
	print_result(t_result *result)
{
	if ((result->neg && result->minus))
	{
		unsigned_minus_removed(result);
		p_zeros(result);
		p_value(result);
		p_spaces(result);
	}
	else if (result->neg && !result->minus)
	{
		p_spaces(result);
		unsigned_minus_removed(result);
		p_zeros(result);
		p_value(result);
	}
	else if (!result->neg && result->minus)
	{
		p_zeros(result);
		p_value(result);
		p_spaces(result);
	}
	else
	{
		p_spaces(result);
		p_zeros(result);
		p_value(result);
	}
}

int
	ds_or_not(t_result *result)
{
	if (result->data->specifier == 'c' || result->data->specifier == '%')
		return (1);
	else if (result->value != NULL)
		return (ft_strlen(result->value));
	return (0);
}

int
	g_parser(va_list alist, char **str_ptr)
{
	int			l;
	int			len_r;
	t_result	*result;

	len_r = 0;
	result = analyser(*str_ptr, alist);
	print_result(result);
	l = format_length(*str_ptr) + 1;
	len_r = result->spaces + result->zeros + ds_or_not(result);
	*str_ptr += l;
	result_destroy(result);
	return (len_r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_analyser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:07:58 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 03:33:37 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser.h"

void
	x_precision_handler(t_format *holder, t_result *result, int size)
{
	if (holder->precision > 0 && holder->precision > size)
	{
		result->pr_anl = holder->precision - size;
		result->zeros = holder->precision - size;
	}
	else if (!hex_to_dec(holder->value) && (holder->precision < 0))
	{
		result->zeros += 1;
		result->pr_anl += 1;
	}
}

void
	x_zero_case_handler(t_format *holder, int *size)
{
	if (!hex_to_dec(holder->value) && holder->specifier != 'p')
		if ((holder->flags_existence & PRECISION)
		&& holder->specifier != 'p' && !hex_to_dec(holder->value))
			*size = 0;
}

void
	p_zero_case_handler(t_format *holder, int *size)
{
	if (((holder->value[2] == '0')) && holder->flags_existence
	& PRECISION && holder->specifier == 'p')
		*size = 2;
}

void
	x_calculator(t_format *holder, t_result *result, int size)
{
	int fw;

	fw = ft_abs(holder->field_width);
	x_zero_case_handler(holder, &size);
	p_zero_case_handler(holder, &size);
	x_precision_handler(holder, result, size);
	if (holder->flags_existence & FW_ZERO)
	{
		if ((!(holder->flags_existence & PRECISION)
		|| holder->precision < 0) && holder->field_width > size)
			result->zeros = holder->field_width - size;
		else if (fw > size)
			result->spaces = fw - result->pr_anl - size;
	}
	else
	{
		if (fw > size)
			result->spaces = fw - result->pr_anl - size;
	}
}

void
	x_intrepert(t_format *holder, t_result *result)
{
	result->data = holder;
	if (holder->minus)
		result->minus = 1;
	if (holder->field_width < 0)
		result->minus = 1;
	if (holder->specifier == 'X')
		ft_to_lower(holder->value);
	result->value = ft_strdup(holder->value);
	x_calculator(holder, result, ft_strlen(result->value));
}

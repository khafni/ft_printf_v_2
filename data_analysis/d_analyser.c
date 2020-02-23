/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_analyser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:40:21 by khafni            #+#    #+#             */
/*   Updated: 2020/02/23 22:48:18 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser.h"

void
	d_precision_handler(t_format *holder, t_result *result, int size)
{
	if (result->neg)
	{
		size--;
	}
	if (holder->precision > 0 && holder->precision > size)
	{
		result->pr_anl = holder->precision - size;
		result->zeros = holder->precision - size;
	}
	else if (!ft_atoi(holder->value) && (holder->precision < 0))
	{
		result->zeros += 1;
		result->pr_anl += 1;
	}
}

void
	d_zero_case_handler(t_format *holder, int *size)
{
	if (holder->flags_existence & PRECISION)
		*size = 0;
}

void
	d_calculator(t_format *holder, t_result *result, int size)
{
	int fw_av;

	fw_av = ft_abs(holder->field_width);
	if (!ft_atoi(holder->value))
		d_zero_case_handler(holder, &size);
	d_precision_handler(holder, result, size);
	if (holder->flags_existence & FW_ZERO)
	{
		if ((!(holder->flags_existence & PRECISION)
		|| holder->precision < 0) && holder->field_width > size)
			result->zeros = holder->field_width - size;
		else if (ft_abs(holder->field_width) > size)
			result->spaces = fw_av - result->pr_anl - size;
	}
	else
	{
		if (ft_abs(holder->field_width) > size)
			result->spaces = fw_av - result->pr_anl - size;
	}
}

void
	d_intrepert(t_format *holder, t_result *result)
{
	result->data = holder;
	if (holder->minus)
		result->minus = 1;
	if (ft_ltoi(holder->value) < 0)
		result->neg = 1;
	if (holder->field_width < 0)
		result->minus = 1;
	result->value = ft_strdup(holder->value);
	d_calculator(holder, result, ft_strlen(result->value));
}

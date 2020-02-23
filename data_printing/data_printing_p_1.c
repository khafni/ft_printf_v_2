/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_printing_p_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:21:39 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 00:25:52 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_printing.h"

void
	p_spaces(t_result *result)
{
	int i;

	i = 0;
	while (i < result->spaces)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void
	p_zeros(t_result *result)
{
	int i;

	i = 0;
	while (i < result->zeros)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
}

int
	check_if_null(t_result *result)
{
	int check;

	check = result->data->flags_existence & PRECISION;
	if (result->data->specifier == 'x' || result->data->specifier == 'X')
	{
		if (!hex_to_dec(result->value) && check)
		{
			return (1);
		}
	}
	else if (result->data->specifier == 'p')
	{
		if (((result->value[2] == '0')) & check)
		{
			ft_putstr_fd("0x", 1);
			return (1);
		}
	}
	else if (!ft_ltoi(result->value) && check)
		return (1);
	return (0);
}

void
	p_num(t_result *result)
{
	long n;

	if (check_if_null(result))
	{
		return ;
	}
	if (!(result->data->specifier == 'd' || result->data->specifier == 'i'))
	{
		ft_putstr_fd(result->value, 1);
		return ;
	}
	n = -1 * ft_ltoi(result->value);
	if (n == MIN_INTEGER)
		n = 2147483648;
	else
	{
		if (result->neg && (ft_ltoi(result->value) != MIN_INTEGER))
			ft_putnbr_long(n);
		else if (ft_ltoi(result->value) == MIN_INTEGER)
			ft_putnbr_long(2147483648);
		else
			ft_putstr_fd(result->value, 1);
	}
	(void)n;
}

void
	ft_print_max_s(t_result *result)
{
	int m;
	int i;

	i = 0;
	m = result->max_characters;
	while (i < m)
	{
		ft_putchar_fd(result->value[i], 1);
		i++;
	}
}

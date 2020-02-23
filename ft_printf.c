/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:05:38 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 00:29:55 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**           |------------------------------|
**           |  this is my implementation   |
**           |  open source except for this |
**           |  ASCII art box which I put   |
**           |  more effort into than the   |
**           |  implementation....          |
**           |  change it at your peril     |
**           |------------------------------|
*/

#include "ft_printf.h"

int
	ft_printf(char *str, ...)
{
	va_list alist;

	g_return = 0;
	va_start(alist, str);
	while (*str)
	{
		if (*str == '%')
		{
			g_parser(alist, &str);
		}
		else
		{
			ft_putchar_fd(*str, 1);
		}
		str++;
	}
	va_end(alist);
	return (g_return);
}

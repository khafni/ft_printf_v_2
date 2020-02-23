/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_printing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:43:46 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 00:46:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_PRINTING_H
# define DATA_PRINTING_H
# include "../data_gathering_abstraction/data_gathering.h"
# include "../data_analysis/analyser.h"
# include "../utills/utills.h"

/*
** prints the resulted number of spaces from the data analysis
** interface
*/
void	p_spaces(t_result *result);
/*
** prints the resulted number of zeros from the data analysis
** interface
*/
void	p_zeros(t_result *result);
/*
** check if the value of a specifier is null or not
*/
int		check_if_null(t_result *result);
/*
** prints numerical specifiers (d, u, i, x, X) value
*/
void	p_num(t_result *result);
/*
** prints the s specifier value value
*/
void	ft_print_max_s(t_result *result);
/*
** the function that prints the value of a specifier
** depending on what specifier it gets
*/
void	p_value(t_result *result);
/*
** function that prints a '-' character when
** we have a negative d/i specifier's value
*/
void	unsigned_minus_removed(t_result *result);
/*
** the main printer function that prints the result of
** the data analysis interface depending on if we have
** the '-' flag or a negative d/i value or not
*/
void	print_result(t_result *result);
/*
** function that returns the length of the specifier
** we have , and returns 1 if we deal with % or c speicifers
*/
int		ds_or_not(t_result *result);
/*
**  the mi
*/
int		g_parser(va_list alist, char **str_ptr);
int		ft_printf(char *str, ...);
# define MAX_INTEGER 0x7fffffff
# define MIN_INTEGER -2147483648
#endif
